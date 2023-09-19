WITH cte AS(
    SELECT DISTINCT(user_id),
    (MAX(post_date :: DATE) OVER(PARTITION BY user_id) - MIN(post_date:: DATE) OVER(PARTITION BY user_id)) AS days_between
    FROM posts
    WHERE post_date BETWEEN '2021-01-01' AND '2021-12-31'
    )

SELECT * 
FROM cte 
WHERE days_between <> 0