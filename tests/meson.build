project('BlackJack_Tests', 'cpp', version: '0.1')

src = [
  'main.cpp',
  'card_tests.cpp',
  'deck_tests.cpp',
  '../src/card.cpp',
  '../src/deck.cpp',
]

include = include_directories('../include/')

gtest_dep = dependency('gtest')

executable(
  'BlackJack_Tests',
  src,
  include_directories: include,
  dependencies: [gtest_dep],
)
