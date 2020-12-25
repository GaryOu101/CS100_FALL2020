#include "../header/rectangle.hpp"

#include "gtest/gtest.h"

TEST(RectangleTest, Constructor){
	Rectangle* r1 = new Rectangle(2, 3);
	EXPECT_EQ(r1->get_width(), 2);
	EXPECT_EQ(r1->get_height(),3);
}

TEST(RectangleTest, ConstructorNeg){
	Rectangle* r1 = new Rectangle(-2, -3);
	EXPECT_EQ(r1->get_width(), -2);
	EXPECT_EQ(r1->get_height(), -3);
}

TEST(RectangleTest, ConstructorZero){
	Rectangle* r1 = new Rectangle(0, 0);
	EXPECT_EQ(r1->get_width(), 0);
	EXPECT_EQ(r1->get_height(), 0);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
