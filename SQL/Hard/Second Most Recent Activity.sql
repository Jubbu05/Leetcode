WITH cte AS(
    SELECT DISTINCT *
    FROM UserActivity
),
cte2 AS(
    SELECT *, 
    ROW_NUMBER() OVER(PARTITION BY username ORDER BY startDate DESC) AS rnk, 
    COUNT(activity) OVER(PARTITION BY username) AS number_of_activities
    FROM cte
)
SELECT username, activity, startDate, endDate
FROM cte2
WHERE rnk = 2 OR number_of_activities = 1