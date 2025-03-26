#include "Table.h"


void Table::passPlayersIndex(){
	_playerturn = (_playerturn + 1) % Table::MAX_PLAYERS;
}

int Table::getSmallBlindIndex() const{
	return (_playerturn + 1) & Table::MAX_PLAYERS;
}

int Table::getBigBlindIndex() const{
	return (_playerturn + 2) & Table::MAX_PLAYERS;
}

int Table::getPlayerTurnIndex() const{
	return (_playerturn + 3) & Table::MAX_PLAYERS;
}

const int Table::getRemainingPlayers() const{

	int remaining_players = 0;
	const int numPlayers = _players.size();
	for (int i = 0; i < numPlayers; i++)
		remaining_players += (_players[i].get()->isPlaying());

	return remaining_players;
}

Table::Table() {
	_deck = new Deck();
	_playerturn = 0;
	_cardsOnTable.reserve(MAX_CARDS_ON_TABLE);
	_cardsCounter = 0;
	_isHandWinningPlayer = false;
}

void Table::addPlayer(std::shared_ptr<Player>& player) {

	if (_players.size() >= MAX_PLAYERS)
		return;

	_players.push_back(player);
	player->setPlayerRole(PlayerRole::NOT_ASSIGNED);
}

void Table::shareOutCards() {

	for (int i = 0; i < _players.size(); i++) {

		std::shared_ptr<Player> p = _players[i];
		if (p->isPlaying()) {

			// Take two cards from the deck and give it to the player
			std::unique_ptr<Card> card = _deck->takeRandomCard();
			p->takeCard(card);
			card = _deck->takeRandomCard();
			p->takeCard(card);
		}
	}
}

void Table::retrieveCardsFromPlayers() {

	for (int i = 0; i < _players.size(); i++) {

		// Take both of player cards
		for (int j = 0; j < Player::MAX_CARDS_ON_HAND; j++) {

			std::shared_ptr<Player> p = _players[i];
			std::unique_ptr<Card> card = p->retrieveCard();
			_deck->retrieveCard(card);
		}
	}
}

void Table::addCardToTable(){
	std::unique_ptr<Card> card = _deck->takeRandomCard();
	_cardsOnTable.push_back(std::move(card));
}

void Table::retrieveCardsFromTable(){

	const int numCards = _cardsCounter;

	for (int i = 0; i < numCards; i++) {
		std::unique_ptr<Card> card = std::move(_cardsOnTable.at(_cardsCounter - 1));
		//_cardsOnTable.pop_back();	// No es neceseario ¿?¿?
		_deck->retrieveCard(card);
	}
	_cardsCounter = 0;
}

void Table::assignRolesToAllPlayers(){
	
	_players.at( _playerturn )->setPlayerRole(PlayerRole::DEALER);
	_players.at( (_playerturn + 1) % Table::MAX_PLAYERS )->setPlayerRole(PlayerRole::SMALL_BLIND);
	_players.at( (_playerturn + 2) % Table::MAX_PLAYERS )->setPlayerRole(PlayerRole::BIG_BLIND);
}

void Table::passTurn(){

	_players.at(  _playerturn )->setPlayerRole(PlayerRole::NOT_ASSIGNED);
	_players.at( (_playerturn + 1) % Table::MAX_PLAYERS )->setPlayerRole(PlayerRole::DEALER);
	_players.at( (_playerturn + 2) % Table::MAX_PLAYERS )->setPlayerRole(PlayerRole::SMALL_BLIND);
	_players.at( (_playerturn + 3) % Table::MAX_PLAYERS )->setPlayerRole(PlayerRole::BIG_BLIND);
	_playerturn = (_playerturn + 1) % Table::MAX_PLAYERS;
}

void Table::playFullHand(){

	HandInfo totalBets, lastBet;
	int totalPot = 0;
	_isHandWinningPlayer = false;


	shareOutCards();
	lastBet = makeForcedPlays();		// Jugadas small blind y big blind
	totalBets.maxBet = std::max(totalBets.maxBet, lastBet.maxBet);
	totalBets.totalBet += lastBet.totalBet;

	lastBet = allPlayersPlayOneHand(totalBets.maxBet);	// Jugadas del resto de jugadores
	totalBets.maxBet = std::max(totalBets.maxBet, lastBet.maxBet);
	totalBets.totalBet += lastBet.totalBet;

	// Poner cartas en la mesa
	for (int i = 0; i < Table::INITIAL_NUM_CARDS_ON_TABLE; i++)
		addCardToTable();

	int cards_left = Table::MAX_CARDS_ON_TABLE - Table::INITIAL_NUM_CARDS_ON_TABLE;
	while (cards_left != 0) {

		// Datos de la mano jugada
		lastBet = allPlayersPlayOneHand(totalBets.maxBet);
		totalBets.maxBet = std::max(totalBets.maxBet, lastBet.maxBet);
		totalBets.totalBet += lastBet.totalBet;

		addCardToTable();
		--cards_left;
	}

	Player* winner = calculateHandWinningPlayer();
	winner->givePrize(totalPot);

	retrieveCardsFromTable();
	retrieveCardsFromPlayers();
}

Table::HandInfo Table::makeForcedPlays() {

	HandInfo bets;
	const int MAX_REMAINING_PLAYERS = getRemainingPlayers();
	int currentRemainingPlayers = MAX_REMAINING_PLAYERS;

	Player* smallBlind = _players.at(getSmallBlindIndex()).get();
	bets.totalBet += smallBlind->makeForcedBet(SMALL_BLIND_BET);
	--currentRemainingPlayers;
	std::cout << "Quedan " << currentRemainingPlayers << " jugadores por jugar!\n";

	Player* bigBlind = _players.at(getBigBlindIndex()).get();
	bets.maxBet = bigBlind->makeForcedBet(BIG_BLIND_BET);
	bets.totalBet += bets.maxBet;
	--currentRemainingPlayers;
	std::cout << "Quedan " << currentRemainingPlayers << " jugadores por jugar!\n";

	std::cout << "Current hand pot is " << bets.totalBet << "$\n";
	std::cout << "Maximun bet is " << bets.maxBet << "$\n";
	std::cout << "Quedan " << currentRemainingPlayers << " jugadores activos!\n";

	return bets;
}

Table::HandInfo Table::allPlayersPlayOneHand(const int& minimumBet){

	HandInfo bets;
	int currentRemainingPlayers = getRemainingPlayers();
	while (currentRemainingPlayers != 0) {

		Player* player = _players.at( getPlayerTurnIndex() ).get();
		Player::Action action = player->makePlay(minimumBet);
	
		if (action.bet == 0)
			player->retire();
		else {
			bets.maxBet += action.bet;
		}

		if (action.restartTurn)
			currentRemainingPlayers = getRemainingPlayers();

		passPlayersIndex();
		char c;
		std::cin >> c;
	}

	return bets;
}

Player* Table::calculateHandWinningPlayer() const{
	return nullptr;
}

void Table::printDeck() {
	_deck->printAllDeck();
}

const std::vector<std::string> Table::getCardsOnTableInfo() const{

	std::vector<std::string> infoList;

	int numCards = 0;
	for (int i = 0; i < _cardsOnTable.size(); i++) {
		infoList.push_back(_cardsOnTable[i]->toString());
		numCards++;
	}

	// 'Añadir' las cartas que no se han puesto aun
	for (numCards; numCards < Table::MAX_CARDS_ON_TABLE; numCards++)
		infoList.push_back(Card::missingCardToString());

	return infoList;
}

const std::vector<std::shared_ptr<Player>> Table::getPlayerList() const{
	return _players;
}