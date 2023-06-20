SELECT *
FROM Students
JOIN Subjects
LEFT JOIN Examinations
ON Students.student_id = Examinations.student_id
AND Subjects.subject_name = Examinations.subject_name
GROUP BY Students.student_id, Subjects.subject_name