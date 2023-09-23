# Write your MySQL query statement below
# select x,y,z, IF(x+y>z and x+z>y and y
# +z>x,"Yes","No") as triangle from Triangle;


select x,y,z, case when ((x+y) > z and (y+z) > x and (z+x) > y) then 'Yes' else 'No' end as triangle from Triangle