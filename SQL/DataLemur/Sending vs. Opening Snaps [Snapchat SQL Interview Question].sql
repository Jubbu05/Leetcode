WITH cte AS (
    SELECT *,
    (CASE WHEN activity_type='open' then time_spent else 0 END) AS t1,
    (CASE WHEN activity_type='send' then time_spent else 0 END) AS t2
    FROM activities a1
    JOIN age_breakdown a2
    ON a1.user_id=a2.user_id
    WHERE activity_type IN ('send','open'))

SELECT age_bucket,
    ROUND(SUM(t2)*100.0/SUM(t1+t2),2) as send_perc,
    ROUND(SUM(t1)*100.0/SUM(t1+t2),2) as open_perc
FROM cte
GROUP BY 1