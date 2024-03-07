#include "gtest/gtest.h"

#include "../game_lib/headers/logic/Game.h"


class GameFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        game = new Game(8);
    }

    virtual void TearDown() {
        delete game;
    }
    Game *game;
};

TEST_F(GameFixture, PossibleMovesForPiece_Test){

    EXPECT_EQ(game->possibleMovesForPiece(0,0).size(), 0);

    EXPECT_EQ(game->possibleMovesForPiece(0,0).size(), 0);

}
