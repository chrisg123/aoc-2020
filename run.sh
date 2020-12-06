#!/bin/bash

print_part() {
    printf '%s%35s%s\n' "- Part ${1}" '#' "${2}"
}
print_result() {
    printf '%s\n' "${1}" | awk '{for(i=0;i<11;i++)printf " ";print $0}'
}

printf '\n%s\n' '[Day 1]'
print_part '1' 'python'

pushd d1/p1 > /dev/null
print_result "$(python main.py)"
popd > /dev/null

print_part '2' 'python'
pushd d1/p2 > /dev/null
print_result "$(python main.py)"
popd > /dev/null

printf '\n%s\n' '[Day 2]'
print_part '1' 'python'
pushd d2/p1 > /dev/null
print_result "$(python main.py)"
popd > /dev/null

print_part '2' 'C'
pushd d2/p2 > /dev/null
make > /dev/null
print_result "$(./app)"
make clean > /dev/null
popd > /dev/null

printf '\n'

