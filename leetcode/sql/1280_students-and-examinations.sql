SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    (
        SELECT 
            COUNT(*)
        FROM Examinations
        WHERE Examinations.student_id = Students.student_id AND
            Examinations.subject_name = Subjects.subject_name   
    ) AS attended_exams
FROM Students
JOIN Subjects
ORDER BY Students.student_id, Subjects.subject_name;
