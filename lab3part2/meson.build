project('lab3part2', 'c',
  default_options : ['c_std=gnu18', 'warning_level=3'],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

exe = executable('part2', 'part2.c', dependencies : m_dep)

subdir('tests')
