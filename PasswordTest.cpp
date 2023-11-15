/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, Multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAA");
	ASSERT_EQ(3,actual);
}
TEST(PasswordTest, special_characters_as_leading_characters) 
{
    Password my_password;
    int actual = my_password.count_leading_characters("???Bee");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, spaces_as_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("    Bee");
    ASSERT_EQ(4, actual);
}
TEST(PasswordTest, no_leading_characters) 
{
    Password my_password;
    int actual = my_password.count_leading_characters("Bee");
    ASSERT_EQ(0, actual);
}
TEST(PasswordTest, check_for_upper_lower_case) 
{
    Password my_password; 
	bool actual = my_password.has_mixed_case("Be"); 
	ASSERT_EQ(true, actual); 
}

TEST(PasswordTest, check_for_upper_lower_case_long) 
{
    Password my_password; 
	bool actual = my_password.has_mixed_case("748Be112E123123"); 
	ASSERT_EQ(true, actual); 
}

TEST(PasswordTest, check_for_empty_phrase) 
{
    Password my_password; 
	bool actual = my_password.has_mixed_case(""); 
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, check_valid_password){
    Password my_password;
    bool actual = my_password.set("beeBEE123");
    ASSERT_EQ(true, actual);
}

TEST(PasswordTest, check_authentication){ 
    Password my_password;
    bool actual = my_password.authenticate("beeBEE123");
    ASSERT_EQ(true, actual);
}

