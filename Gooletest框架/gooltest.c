/*************************************************************************
	> File Name: gooltest.c
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月23日 星期日 21时48分27秒
 ************************************************************************/

#include<gtest/gtest.h>
int add(int a,int b){
    return a+b;
}
TEST(testCase,test0){
    EXPECT_EQ(add(3,3),5);
}
int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
