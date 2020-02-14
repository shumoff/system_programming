gtest = dependency('gtest', main: true)
test(
    'trait',
    executable(
        'trait_test',
        include_directories: src,
        sources: ['trait_test.cc'],
        dependencies: [gtest]
    )
)

test(
    'polynomial',
    executable(
        'polynomial_test',
        include_directories: src,
        sources: ['polynomial_test.cc'],
        dependencies: [gtest]
    )
)

test(
    'schur_transform',
    executable(
        'schur_transform_test',
        include_directories: src,
        sources: ['schur_transform_test.cc'],
        dependencies: [gtest]
    )
)
