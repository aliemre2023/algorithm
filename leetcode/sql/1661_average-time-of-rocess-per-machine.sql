SELECT 
    DISTINCT a1.machine_id,
    ROUND((
        (
            SELECT AVG(timestamp)
            FROM Activity a2
            WHERE a2.machine_id = a1.machine_id 
                AND activity_type = 'end'
        )
        - 
        (
            SELECT AVG(timestamp)
            FROM Activity a2
            WHERE a2.machine_id = a1.machine_id 
                AND activity_type = 'start'
        ) 
    ), 3) AS processing_time
FROM Activity a1
ORDER BY a1.machine_id, a1.process_id;