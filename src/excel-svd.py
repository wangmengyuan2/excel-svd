'''
Created on 2016/7/30

@author: neo
'''
import sys
import pandas as pd
from sys import stdout
import numpy as np
from numpy import nan

pre_layer=1
max_layer=-1
tag_list=[]
fields_name_list=[]

def push_tag_list(tag) :
    global tag_list    
    tag_list.append(tag)

def pop_tag_list() :
    global tag_list

    if len(tag_list) > 0 :
        value = tag_list[-1]
        del tag_list[-1]
        return value
    else:
        return (-1,"")

def pop_tag_list_by_layer(layer):
    global pre_layer
    
    #print 'layer=',layer,',clayer=',clayer,',pre_layer=',pre_layer    
    if layer < pre_layer :
        (layer1,tag) = pop_tag_list()
        
        #print 'layer1=', layer1, 'clayer=',clayer
        while layer1 >= layer :
            print_ident(layer1)
            tag_print_end(tag)
            (layer1,tag) = pop_tag_list()
            #print 'layer1=', layer1, 'clayer=',clayer   
            
        #push back the last 
        if layer1 != -1 :
            push_tag_list((layer1, tag))
    


def print_ident(layer):
    loops = layer
    while loops > 0 :
        stdout.write('  ')
        loops = loops - 1

    
def tag_one_print(name):
    stdout.write('<'+str(name).strip()+'>\r\n')

def tag_two_print(name, value):
    stdout.write('<'+str(name).strip()+'>'+str(value).strip()+'</'+str(name).strip()+'>\r\n')

def tag_print_end(tag):
    stdout.write('</'+str(tag).strip()+'>\r\n')


def parse_row(this_row, start_column):
    global pre_layer
    global fields_name_list
    global max_layer
    
    
    if len(this_row) < 2+start_column : 
        return

    try:    
        layer = int(this_row[start_column])
    except:
        return
    
    name = str(this_row[start_column+1]).strip()
    
    pop_tag_list_by_layer(layer)
        
    #print 'layer=',layer,' name=', name
    if layer < 100 :
        if layer % 2 == 0: #one tag, push-pop
            print_ident(layer)
            tag_one_print(name)
            push_tag_list((layer,name))
        elif layer % 2 == 1: #name-value, no push
            value = str(this_row[start_column+2]).strip()
            print_ident(layer)
            tag_two_print(name, value)
            
        if layer > max_layer : 
            max_layer = layer
    else:
        field_layer = max_layer + layer - 99
        if layer == 100: #fields
            fields_name_list = this_row[start_column+1:]
            #print tag1 : field
            field_name1 = 'fields'
            print_ident(field_layer)
            tag_one_print(field_name1)
            push_tag_list((field_layer, field_name1))
        elif layer == 101: #each field
            fields_value_list = this_row[start_column+1:]
            fields_num = len(fields_value_list)
            #print tag2 : field
            field_name2 = 'field'
            print_ident(field_layer)
            tag_one_print(field_name2)
            #print each item
            item = 0
            while item < fields_num :
                print_ident(field_layer+2)
                tag_two_print(fields_name_list[item], fields_value_list[item])
                item = item + 1
            print_ident(field_layer)
            tag_print_end(field_name2)
                
    pre_layer = layer
    


#
def parse_main_table(table1):
    #print table1
    rows = table1.shape[0]
    columns = table1.shape[1]
    #print "rows=", rows
    #print "column=", columns
    
    # find Layer
    cur_row = 1
    cur_column = 0
    while cur_column < columns :
        if table1.iloc[1][cur_column] == 'Layer' :
            break
        cur_column = cur_column + 1
        
    if cur_column >= columns :
        print 'FAIL Can not find Layer'
        return
    start_column = cur_column
    cur_row=2
    
    while cur_row < rows:
        parse_row(table1.iloc[cur_row], start_column)
        cur_row = cur_row + 1
             
#    for row in rows :
#        print 'row=',row,table1[row]
    


def parse_xls(filename1):
    #print "parse_xls() :", filename1
    
    # read to pandas from excel 
    xls = pd.ExcelFile(filename1)
    
    # get sheet names list 
    sheet_names = xls.sheet_names
    sheet_num = len(sheet_names)
    if sheet_num < 2 :
        print "sheet nums ", sheet_num, "<2"
        return
    #print sheet_names
    
    #check first sheet's name, need to be platform
    if sheet_names[0] != 'platform' : 
        print "excel file is not correct, the first sheet's tag needs to be platform"
        return
    
    table1 = xls.parse(sheet_names[0])
    parse_main_table(table1)
    
    
    table2 = xls.parse(sheet_names[1])
    parse_main_table(table2)
    
    pop_tag_list_by_layer(0) #pop all

    
    
def print_pre_svd():
    print '<?xml version="1.0" encoding="utf-8"?>'
    print
    print '<device schemaVersion="1.1" xmlns:xs="http://www.w3.org/2001/XMLSchema-instance" xs:noNamespaceSchemaLocation="CMSIS-SVD.xsd" >'

def print_post_svd():
    print '</device>'
    

if __name__ == "__main__":
    #check parameters, need to have Excel file name
    if len(sys.argv) < 2:
        print "python excel-svd.py <Excel filename>"
    else: 
        print_pre_svd()
        parse_xls(sys.argv[1])
        print_post_svd()

        
        
    
