# Write your MySQL query statement below
# select s.student_id,
# s.student_name,
# su.subject_name,
# count(e.subject_name) as attended_exams
# from Students s 
# cross join subjects su
# left join Examinations e 
# on e.student_id=s.student_id and e.subject_name =su.subject_name
# group by s.student_id,su.subject_name,s.student_name
# order by s.student_id,su.subject_name




SELECT s.student_id, s.student_name, s.subject_name, count(e.subject_name) AS attended_exams
FROM (SELECT * FROM Students JOIN Subjects) AS s
LEFT JOIN Examinations e
ON s.student_id = e.student_id 
AND s.subject_name = e.subject_name 
GROUP BY s.student_id,s.subject_name,s.student_name
order by s.student_id, s.subject_name