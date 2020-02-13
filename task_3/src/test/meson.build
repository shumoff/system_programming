gtest = dependency('gtest', main: true)
test(
    'message',
    executable(
        'message_test',
        include_directories: src,
        sources: ['message_test.cc'],
        dependencies: [gtest]
    )
)

test(
    'cat',
    executable(
        'cat_test',
        include_directories: src,
        sources: ['cat_test.cc'],
        dependencies: [gtest]
    )
)

test(
    'tie',
    executable(
        'tie_test',
        include_directories: src,
        sources: ['tie_test.cc'],
        dependencies: [gtest]
    )
)
