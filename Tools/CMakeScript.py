# !/usr/bin/python

import sys
import os
import fnmatch
import ntpath
import re

# This scripts does generate source files list for CMakeLists as it's a nightmare to do manually

include_exts = ('.tpp', '.h', '.hpp', '.ipp')
source_exts = ('.cpp', '.c', '.mm')

def get_cpp_sources(path):
	files = ([], [])
	file_list = os.listdir(path)
	for file in file_list:
		lower_filename = file.lower()
		# Source is 0 Include is 1
		if (lower_filename.endswith(source_exts)):
			files[0].append(path + '\\' + file)
		if (lower_filename.endswith(include_exts)):
			files[1].append(path + '\\' + file)
	return files
	
def absolute_path_to_relative(path, project_folder):
	base_path = project_folder.replace('\\', '/')
	file_path = path.replace('\\', '/')
	common_prefix = os.path.commonprefix([base_path, file_path])
	#print('Common=>' + file_path[len(common_prefix):])
	return './' + file_path[len(common_prefix):]

def generate_folder_group(out_file, name, is_root, source_files):
			if (is_root):
				name = 'Root'
			out_file.write('#### ' + name + ' ####\n')			
			out_file.write('##########\n')
			out_file.write('\n')
			
			out_file.write('set(FOLDER_GROUP ' + name + ')\n')
			
			out_file.write('set(\n')
			out_file.write('\t\"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources\"\n')
			for file in source_files[0]:
				relative_path = absolute_path_to_relative(file, sys.argv[2])
				out_file.write('\t\"' + relative_path + '\"\n')
			out_file.write(')\n')
			
			out_file.write('set(\n')
			out_file.write('\t\"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes\"\n')
			for file in source_files[1]:
				relative_path = absolute_path_to_relative(file, sys.argv[2])
				out_file.write('\t\"' + relative_path + '\"\n')
			out_file.write(')\n')
			
			out_file.write('source_group(\n')
			if (not is_root):
				out_file.write('\t\"${FOLDER_GROUP}\\\\"\n')
			else:
				out_file.write('\t\"\\\\"\n')
			out_file.write('\tFILES\n')
			out_file.write('\t${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources}\n')
			out_file.write(')\n')
			
			out_file.write('source_group(\n')
			if (not is_root):
				out_file.write('\t\"${FOLDER_GROUP}\\\\"\n')
			else:
				out_file.write('\t\"\\\\"\n')
			out_file.write('\tFILES\n')
			out_file.write('\t${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}\n')
			out_file.write(')\n\n')
	

if len(sys.argv) < 4:
	sys.exit()
	
print(sys.argv[0] + '(' + sys.argv[1] + '.' + sys.argv[3] + ') => Generating CMakeLists.txt at ' + sys.argv[2])

source_filename = './sources.cmake'
cmake_lists = './CMakeLists.txt'
tmp_filename = source_filename + '.tmp'

out_cmakefile = open(source_filename, 'w')

all_group_list = []
for path, dirs, files in os.walk(sys.argv[2]):
	is_root = False
	source_files = get_cpp_sources(path)
	if (len(source_files[0]) > 0 or len(source_files[1]) > 0):
		folder_name = ntpath.basename(path)
		print("=>" + folder_name + "/" + path)
		if path is sys.argv[2]:
			folder_name = 'Root'
			is_root = True
		all_group_list = all_group_list + [folder_name]
		generate_folder_group(out_cmakefile, folder_name, is_root, source_files)
			

out_cmakefile.write('set(\n')
out_cmakefile.write('\t\"SourceFiles\"\n')

for group in all_group_list:
	out_cmakefile.write('\t${${CMAKE_PROJECT_NAME}' + group + 'Sources}\n')
	out_cmakefile.write('\t${${CMAKE_PROJECT_NAME}' + group + 'Includes}\n')
	
out_cmakefile.write(')\n')
out_cmakefile.close()

is_in_generate_section = False

cmake_lists_file = open(sys.argv[2] + '/' + cmake_lists, 'r', newline='\n')
sources_file = open(source_filename, 'r')
tmp_file = open(sys.argv[2] + '/' + tmp_filename, 'w', newline='\n')

for line in cmake_lists_file.readlines():
	if not is_in_generate_section and re.match('## SOURCE_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT\'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT', line):
		is_in_generate_section = True
		tmp_file.writelines([line])
		tmp_file.writelines(sources_file.readlines())
	if re.match('## SOURCE_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT\'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT', line):
		is_in_generate_section = False
	if not is_in_generate_section:
		tmp_file.writelines([line])

		
cmake_lists_file.close()
tmp_file.close()

cmake_lists_file = open(sys.argv[2] + '/' + cmake_lists, 'w', newline='\n')
tmp_file = open(sys.argv[2] + '/' + tmp_filename, 'r', newline='\n')
cmake_lists_file.writelines(tmp_file.readlines())

tmp_file.close()
sources_file.close()

try:
	os.remove(sys.argv[2] + '/' + tmp_filename)
except:
	pass
try:
	os.remove(sys.argv[2] + '/' + source_filename)
except:
	pass
