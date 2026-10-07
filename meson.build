project(
  'marcel',
  'c',
  meson_version: '>= 1.3.0',
  version: '0.1',
  default_options: ['warning_level=3'],
)

dependencies = []

sources = [
  'marcel.lex.c',
]

executable(
  'marcel',
  sources + 'main.c',
  dependencies: dependencies,
  install: true,
)

lex_test = executable(
  'test_lex',
  sources + 'marcel.test.lex.c',
  dependencies: dependencies,
)

test('lex test', lex_test)