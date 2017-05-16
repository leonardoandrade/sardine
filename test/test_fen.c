#include "../vendor/unity/unity.h"
#include "../position/definitions.h"
#include "../position/board_display.h"
#include "../position/fen.h"
#include "../position/position.h"

void testBuildFromFen1() {
	char fen[] = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
	Position * position = fenToPosition(fen);
	//dumpPosition(position);
    //printf("w: %d b:%d",countWhitePiecesOfPosition(position), countBlackPieces(position));
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(countPiecesOfPosition(position) == 32);
    TEST_ASSERT_TRUE(countWhitePieces(position) == 16);
    TEST_ASSERT_TRUE(countBlackPieces(position) == 16);
	TEST_ASSERT_TRUE(!isWhiteToMove(position));
	TEST_ASSERT_TRUE(isWhiteKingSideCastle(position));
	TEST_ASSERT_TRUE(isWhiteQueenSideCastle(position));
	TEST_ASSERT_TRUE(isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(isBlackQueenSideCastle(position));
}

void testBuildFromFen2() {
	char fen[] = "5k2/8/2r5/2P5/4K3/8/8/7R w - - 13 2";
	Position * position = fenToPosition(fen);
	//dumpPosition(position);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(countPiecesOfPosition(position) == 5);
	TEST_ASSERT_TRUE(countWhitePieces(position) == 3);
	TEST_ASSERT_TRUE(countBlackPieces(position) == 2);
	TEST_ASSERT_FALSE(isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(isBlackKingSideCastle(position));
	TEST_ASSERT_FALSE(isBlackQueenSideCastle(position));
}

void testBuildFromFen3() {
	char fen[] = "r3k3/8/8/8/8/8/1P7/4K2R b Kq - 20 2";
	Position * position = fenToPosition(fen);
	TEST_ASSERT_NOT_NULL(position);
	TEST_ASSERT_TRUE(countPiecesOfPosition(position) == 5);
	TEST_ASSERT_TRUE(countWhitePieces(position) == 3);
	TEST_ASSERT_TRUE(countBlackPieces(position) == 2);
	TEST_ASSERT_FALSE(isWhiteToMove(position));
	TEST_ASSERT_TRUE(isWhiteKingSideCastle(position));
	TEST_ASSERT_FALSE(isWhiteQueenSideCastle(position));
	TEST_ASSERT_FALSE(isBlackKingSideCastle(position));
	TEST_ASSERT_TRUE(isBlackQueenSideCastle(position));
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
