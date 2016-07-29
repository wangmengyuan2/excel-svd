'''
Created on 2016/7/30

@author: neo
'''
import sys
import pandas as pd

def parse_xls(filename1):
    print "parse_xls() :", filename1
    xls = pd.ExcelFile(filename1)
    sheet_names = xls.sheet_names
    sheet_num = len(sheet_names)
    if sheet_num < 2 :
        print "sheet nums ", sheet_num, "<2"
        return
    print sheet_names
    table1 = xls.parse(sheet_names[0], index_col=None, na_values=['NA'])
    print table1
    rows = table1.irow(0)
    columns = table1.icol(0)
    print "rows=", rows
    print "column=", table1.irow(0)
    for row in rows :
        print 'row=',row,table1[row]
    

if __name__ == "__main__":
    if len(sys.argv) >= 2:
        parse_xls(sys.argv[1])       
    else:
        print "python excel-svd.py <filename>"
        
    
