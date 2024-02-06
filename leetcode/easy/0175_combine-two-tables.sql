# Write your MySQL query statement below
SELECT P.firstName, P.LastName, A.City, A.State 
    FROM Person P
LEFT JOIN Address A
    on P.PersonId = A.PersonId;