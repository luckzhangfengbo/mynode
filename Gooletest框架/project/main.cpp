/*************************************************************************
	> File Name: main.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年01月12日 星期日 15时38分39秒
 ************************************************************************/
#include<stdio.h>
#include <haizei_test.h>
#include <unit.h>
//#include <gtest/gtest.h>

__attribute__((constructor))
int haizei_init() {
    printf("hello haizei\n");
    return 0;
}


TEST(test, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-1, -7), -8);
}

TEST(A, B) {
    EXPECT_EQ(add(5, 6), 11);
}


int main(int argc, char *argv[]) {
//    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
