# excel-svd
excel-svd

## What is this?

This is the tool to convert from excel file to the CMSIS-SVD format;

[CMSIS-SVD](http://www.keil.com/pack/doc/cmsis/SVD/html/index.html) is a kind of XML, 

so the program can be used as the XML editor with excel

## excel file 

The format I use is .xlsx which is made from google doc. 

A special 'Layer' is used to help the convertion.

>   The even number, like 2,4,.., means the tag, which enclose the following layers bigger then it. 
  
>   The odd number, like 1,3,5,..., means one line tag/value format, as the format: &lt;tag>value&lt;/tag>'

example : 

2 sheets inside
(1) platform 

![platform, cpu definition](https://github.com/neojou/excel-svd/blob/master/doc/cmsis-0.png)

(2) peripheral

    - Timer
    
![peripheral, timer](https://github.com/neojou/excel-svd/blob/master/doc/cmsis-1.png)
    
    - register
    
![peripheral, timer](https://github.com/neojou/excel-svd/blob/master/doc/cmsis-2.png)
    

## Test Run 

python excel-svd.py ../data/svd-test.xlsx > NAME.svd

Then we can use [SVDConv program](http://www.keil.com/pack/doc/cmsis/svd/html/svd__s_v_d_conv_pg.html) to covert it

./SVDConv.exe ./NAME.svd --generate=header --fields=struct --fields=macro

Then we can get NAME.h

### python 2.7 is used here
