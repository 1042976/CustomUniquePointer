//
// Created by Xiaodong Liu on 8/22/22.
//
#include "CustomUniquePointer.h"
#include "gtest/gtest.h"

namespace ns{
    class Rectangle{
    public:
        int width, height;
        Rectangle(int _width = 1, int _height = 1): width(_width), height(_height){}
    };

    //test unique_ptr<T>
    class CustomUniquePointerTest: public ::testing::Test{
    protected:
        unique_ptr<Rectangle> A, B, C;
        CustomUniquePointerTest():B(new Rectangle(1, 1)), C(new Rectangle(8,10)){}
    };

    TEST_F(CustomUniquePointerTest, DefualtContructor){
        EXPECT_EQ(A.get(), nullptr);
    }

    TEST_F(CustomUniquePointerTest, OneValContructor){
        EXPECT_EQ(B->height, 1);
        EXPECT_EQ(B->width, 1);
        EXPECT_EQ(C->height, 10);
        EXPECT_EQ(C->width, 8);
    }

    TEST_F(CustomUniquePointerTest, MoveConstructor){
        unique_ptr<Rectangle> D(move(B));
        EXPECT_EQ(D->width, 1);
        EXPECT_EQ(D->height, 1);
    }

    TEST_F(CustomUniquePointerTest, MoveAssignmentOperator){
        A = move(B);
        EXPECT_EQ(A->width, 1);
        EXPECT_EQ(A->height, 1);
        A = move(A);
        EXPECT_EQ(A->width, 1);
        EXPECT_EQ(A->height, 1);
    }

    TEST_F(CustomUniquePointerTest, Dereference){
        EXPECT_EQ((*B).width, 1);
        EXPECT_EQ((*B).height, 1);
    }

    TEST_F(CustomUniquePointerTest, Bool){
        bool state = true;
        state = (bool)A;
        EXPECT_EQ(state, false);
        state = (bool)B;
        EXPECT_EQ(state, true);
    }

    //test unique_ptr<T[]>
    class CustomUniquePointerArrayTest: public ::testing::Test{
    protected:
        CustomUniquePointerArrayTest():B(new Rectangle[10]), C(new Rectangle(8,10)){}

        unique_ptr<Rectangle[]> A, B, C;
    };

    TEST_F(CustomUniquePointerArrayTest, DefualtContructor){
        EXPECT_EQ(A.get(), nullptr);
    }

    TEST_F(CustomUniquePointerArrayTest, OneArrayContructor){
        EXPECT_EQ(B[0].width, 1);
        EXPECT_EQ(B[0].height, 1);
        EXPECT_EQ(B[9].height, 1);
        EXPECT_EQ(B[9].height, 1);
    }

    TEST_F(CustomUniquePointerArrayTest, MoveConstructor){
        unique_ptr<Rectangle[]> D(move(B));
        EXPECT_EQ(D[0].width, 1);
        EXPECT_EQ(D[0].height, 1);
    }

    TEST_F(CustomUniquePointerArrayTest, MoveAssignmentOperator){
        A = move(B);
        EXPECT_EQ(A[1].width, 1);
        EXPECT_EQ(A[1].height, 1);
        A = move(A);
        EXPECT_EQ(A[1].width, 1);
        EXPECT_EQ(A[1].height, 1);
    }

    TEST_F(CustomUniquePointerArrayTest, Reference){
        EXPECT_EQ(B->height, 1);
        EXPECT_EQ(B->width, 1);
    }

    TEST_F(CustomUniquePointerArrayTest, Dereference){
        EXPECT_EQ((*B).width, 1);
        EXPECT_EQ((*B).height, 1);
        B[1].height = 100;
        B[2].width = 9;
        EXPECT_EQ(B[1].height, 100);
        EXPECT_EQ(B[2].width, 9);
    }

    TEST_F(CustomUniquePointerArrayTest, Bool){
        bool state = true;
        state = (bool)A;
        EXPECT_EQ(state, false);
        state = (bool)B;
        EXPECT_EQ(state, true);
    }

}



