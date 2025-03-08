SELECT 
    DISTINCT Visits.customer_id,
    COUNT(*) AS count_no_trans
FROM Visits
WHERE Visits.visit_id NOT IN (
    SELECT DISTINCT Transactions.visit_id
    FROM Transactions 
)
GROUP BY Visits.customer_id;