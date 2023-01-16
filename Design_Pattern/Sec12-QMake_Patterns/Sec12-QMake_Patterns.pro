TEMPLATE = subdirs
SUBDIRS     = \
              98_Start_Script_B_Compiling \
              99_Start_Script_A_Compiling \
              100_Start_Script_BA_Linking \
              101_Subdir_Ordered \
              102_Project_Include_Files


CONFIG += ordered
CONFIG += sdk_no_version_check
