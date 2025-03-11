#include "Table.h"


int Table::passPlayersIndex(){
	_playerturn = (_playerturn + 1) % Table::MAX_PLAYERS;
	return _playerturn;
}

int Table::getNextPlayersIndex() const{
	return (_playerturn + 1) & Table::MAX_PLAYERS;
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

void Table::playHand(){

	_isHandWinningPlayer = false;
	shareOutCards();
	

	while (!_isHandWinningPlayer) {

		const int MAX_REMAINING_PLAYERS = getRemainingPlayers();
		int currentRemainingPlayers = MAX_REMAINING_PLAYERS;
		std::cout << "Quedan " << currentRemainingPlayers << " jugadores activos!\n";

		// Coger al small blind + forzar jugada

		// Coger al big blind + forzar jugada
			
		// BUCLE
			// Coger al jugador al que le toque + esperar su jugada
			// Hasta completar todos sin que hagan 'RAISE'

			// Si hay 'raise' -> reiniciar turnos -> comenzar 'nueva ronda' desde el ultimo en jugar

		// Seleccionar ganador(ultimo en jugar o unico activo)
		break;	// De momento para no entrar en bucle infinito
	}

	// Restablecer actividad(bool)
	// Pasar turno

	retrieveCardsFromTable();
	retrieveCardsFromPlayers();
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
