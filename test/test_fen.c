#include "../vendor/unity/unity.h"
#include "../position/definitions.h"
#include "../position/board_display.h"
#include "../position/fen.h"
#include "../position/position.h"

void testBuildFromFen1() {
	char fen[] = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq e3 1 2";
	Position * position = Fen_fenToPosition(fen);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_EQUAL_INT(32, Position_countPiecesOfPosition(position));
	TEST_ASSERT_EQUAL_INT(16, Position_countWhitePieces(position));
	TEST_ASSERT_EQUAL_INT(16, Position_countBlackPieces(position));
	TEST_ASSERT_FALSE(Position_isWhiteToMove(position));
	TEST_ASSERT_TRUE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackQueenSideCastle(position));
	TEST_ASSERT_EQUAL_INT(4, Position_getEnPassantColumn(position));
	TEST_ASSERT_EQUAL_INT(1, Position_getHalfMoveClock(position));
	TEST_ASSERT_EQUAL_INT(2, Position_getFullMoveCount(position));
	dumpPosition(position);
}

void testBuildFromFen2() {
	char fen[] = "5k2/8/2r5/2P5/4K3/8/8/7R w - - 13 20";
	Position * position = Fen_fenToPosition(fen);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(Position_isWhiteToMove(position));
	TEST_ASSERT_EQUAL_INT(5, Position_countPiecesOfPosition(position));
	TEST_ASSERT_EQUAL_INT(3, Position_countWhitePieces(position));
	TEST_ASSERT_EQUAL_INT(2, Position_countBlackPieces(position));
	TEST_ASSERT_FALSE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackQueenSideCastle(position));
	TEST_ASSERT_EQUAL_INT(0, Position_getEnPassantColumn(position));
}

void testBuildFromFen3() {
	char fen[] = "r3k3/8/8/8/8/8/1P7/4K2R b Kq - 20 84";
	Position * position = Fen_fenToPosition(fen);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_EQUAL_INT(5, Position_countPiecesOfPosition(position));
	TEST_ASSERT_EQUAL_INT(3, Position_countWhitePieces(position));
	TEST_ASSERT_EQUAL_INT(2, Position_countBlackPieces(position));
	TEST_ASSERT_FALSE(Position_isWhiteToMove(position));
	TEST_ASSERT_TRUE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackQueenSideCastle(position));	
	TEST_ASSERT_EQUAL_INT(20, Position_getHalfMoveClock(position));
	TEST_ASSERT_EQUAL_INT(84, Position_getFullMoveCount(position));
}

void testAllFen() {
	RUN_TEST(testBuildFromFen1);
	RUN_TEST(testBuildFromFen2);
	RUN_TEST(testBuildFromFen3);
}

int main() {
	UNITY_BEGIN();
	testAllFen();
	return UNITY_END();
}
