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
