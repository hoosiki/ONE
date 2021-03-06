/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "luci/IR/Nodes/CircleNeg.h"

#include "luci/IR/CircleDialect.h"
#include "luci/IR/CircleNodeVisitor.h"

#include <gtest/gtest.h>

TEST(CircleNegTest, constructor)
{
  luci::CircleNeg neg_node;

  ASSERT_EQ(luci::CircleDialect::get(), neg_node.dialect());
  ASSERT_EQ(luci::CircleOpcode::NEG, neg_node.opcode());

  ASSERT_EQ(nullptr, neg_node.x());
}

TEST(CircleNegTest, input_NEG)
{
  luci::CircleNeg neg_node;
  luci::CircleNeg node;

  neg_node.x(&node);
  ASSERT_NE(nullptr, neg_node.x());

  neg_node.x(nullptr);
  ASSERT_EQ(nullptr, neg_node.x());
}

TEST(CircleNegTest, arity_NEG)
{
  luci::CircleNeg neg_node;

  ASSERT_NO_THROW(neg_node.arg(0));
  ASSERT_THROW(neg_node.arg(1), std::out_of_range);
}

TEST(CircleNegTest, visit_mutable_NEG)
{
  struct TestVisitor final : public luci::CircleNodeMutableVisitor<void>
  {
  };

  luci::CircleNeg neg_node;

  TestVisitor tv;
  ASSERT_THROW(neg_node.accept(&tv), std::exception);
}

TEST(CircleNegTest, visit_NEG)
{
  struct TestVisitor final : public luci::CircleNodeVisitor<void>
  {
  };

  luci::CircleNeg neg_node;

  TestVisitor tv;
  ASSERT_THROW(neg_node.accept(&tv), std::exception);
}
