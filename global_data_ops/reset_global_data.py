'''
This file resets all the global data available.
'''

import pandas as pd
import os
from reset_global_colour_house_wise_data import *
from reset_global_IR_ratio import *
from reset_global_white_level_wise_data import *
from reset_global_block_data import *
from reset_global_I_and_R import *
from reset_house_wise_IR import *


'''
A variable to get current working directory
'''

cwd = os.getcwd()

'''
First reset global block data
'''

reset_block_data()


'''
Reset global IR ratio
'''


reset_global_IR()


'''
Reset global_colour_house_wise_data.csv
'''

reset_global_colour_house_wise_data()


'''
reset global_white_level_wise_data
'''

reset_white_level_wise_data()


'''
Reset global investment and return figures
'''

reset_global_I_and_R()


'''
Reset house wise investment and return
'''


reset_house_wise_IR()



'''
Now reset the number of times the game has been simulated to 0
'''

with open(parent_folder+'/visits.txt',"w") as visits_file:
    visits_file.write('0')
    visits_file.close()
    