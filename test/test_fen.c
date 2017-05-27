#include "../vendor/unity/unity.h"
#include "../position/definitions.h"
#include "../position/board_display.h"
#include "../position/fen.h"
#include "../position/position.h"

void testBuildFromFen1() {
	char fen[] = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq e3 1 2";
	Position * position = fenToPosition(fen);
	//dumpPosition(position);
    printf("w: %d b:%d",Position_countWhitePieces(position), Position_countBlackPieces(position));
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(Position_countPiecesOfPosition(position) == 32);
    TEST_ASSERT_TRUE(Position_countWhitePieces(position) == 16);
    TEST_ASSERT_TRUE(Position_countBlackPieces(position) == 16);
	TEST_ASSERT_TRUE(!Position_isWhiteToMove(position));
	TEST_ASSERT_TRUE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackQueenSideCastle(position));
	TEST_ASSERT_TRUE(Position_getEnPassantColumn(position) == 5);
}

void testBuildFromFen2() {
	char fen[] = "5k2/8/2r5/2P5/4K3/8/8/7R w - - 13 2";
	Position * position = fenToPosition(fen);
	//dumpPosition(position);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(Position_countPiecesOfPosition(position) == 5);
	TEST_ASSERT_TRUE(Position_countWhitePieces(position) == 3);
	TEST_ASSERT_TRUE(Position_countBlackPieces(position) == 2);
	TEST_ASSERT_FALSE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackQueenSideCastle(position));
}

void testBuildFromFen3() {
	char fen[] = "r3k3/8/8/8/8/8/1P7/4K2R b Kq - 20 2";
	Position * position = fenToPosition(fen);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(Position_countPiecesOfPosition(position) == 5);
	TEST_ASSERT_TRUE(Position_countWhitePieces(position) == 3);
	TEST_ASSERT_TRUE(Position_countBlackPieces(position) == 2);
	TEST_ASSERT_FALSE(Position_isWhiteToMove(position));
	TEST_ASSERT_TRUE(Position_isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(Position_isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(Position_isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(Position_isBlackQueenSideCastle(position));

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
