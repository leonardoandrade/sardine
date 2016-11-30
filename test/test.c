#include "../vendor/unity/unity.h"
#include "../position/definitions.h"
#include "../position/board_display.h"
#include "../position/fen.h"
#include "../position/position.h"


void testBuildFromFen() {
	char fen[] = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
	Position * position = fenToPosition(fen);
	dumpPosition(position);
	TEST_ASSERT_NOT_NULL(position);
	printf("-->%d\n", countPiecesOfPosition(position));
	TEST_ASSERT_TRUE(countPiecesOfPosition(position) == 32);
    TEST_ASSERT_TRUE(countWhitePiecesOfPosition(position) == 16);
    TEST_ASSERT_TRUE(countBlackPiecesOfPosition(position) == 16);

}

int main() {
	UNITY_BEGIN();
	RUN_TEST(testBuildFromFen);
	return UNITY_END();
}