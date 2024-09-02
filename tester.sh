#!/bin/bash

TESTER=./checker

result=$(./push_swap $1)

echo "$result" | $TESTER $1
echo "$result" | wc -l
