gtest = dependency('gtest', main: true)
test(
    'ostream_iterator_test',
    executable(
        'ostream_iterator_test',
        include_directories: src,
        sources: ['ostream_iterator_test.cc'],
        dependencies: [gtest]
    )
)

test(
    'merge_sort_test',
    executable(
        'merge_sort_test',
        include_directories: src,
        sources: ['merge_sort_test.cc'],
        dependencies: [gtest]
    )
)
