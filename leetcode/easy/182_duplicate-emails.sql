# Write your MySQL query statement below
SELECT DISTINCT(p.email) FROM Person p, Person diff

WHERE p.id <> diff.id 
    AND p.email = diff.email