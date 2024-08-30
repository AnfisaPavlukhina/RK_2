#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>

#include "res_h.cpp"

class MRestaurant  : public Restaurant {
public:
  MOCK_METHOD(void, CookSteak, (), ());
};
using ::testing::AtLeast;

TEST (Abstract, Mock) {
  MRestaurant mr;
  EXPECT_CALL(mr, CookSteak()).Times(AtLeast(1));
  mr.CookSteak();

}

TEST (Steak, test_cout) {
  Restaurant restaurant;
  testing::internal::CaptureStdout();
  restaurant.CookSteak();
  const std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Let's cook a steak!\nBuy Frying Pan in cook shop.\nBuy Beef in grocery store.\nBuy Sauce in grocery store.\nBuy Salt in grocery store.\nBuy MSG in grocery store.\nBuy Dish in cook shop.\nHere is a great steak!\n\n");
}

TEST (Pasta, test_cout) {
  Restaurant restaurant;
  testing::internal::CaptureStdout();
  restaurant.CookPasta();
  const std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Let's cook a pasta!\nBuy Frying Pan in cook shop.\nBuy Noodle in grocery store.\nBuy Sauce in grocery store.\nBuy MSG in grocery store.\nBuy Dish in cook shop.\nHere is a delicious pasta!\n\n");
}

