project('lab3part3', 'c',
  default_options : ['c_std=gnu18', 'warning_level=3'],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

exe = executable('part3', 'part3.c', dependencies : m_dep)

subdir('tests')
