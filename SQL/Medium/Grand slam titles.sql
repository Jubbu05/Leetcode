WITH cte AS(
    SELECT
        year,
        'Wimbledon' AS tournament,
        Wimbledon AS winner
    UNION
    SELECT
        year,
        'Fr_open' AS tournament,
        Fr_open AS winner
    UNION
    SELECT
        year,
        'Us_open' AS tournament,
        Us_open AS winner
    UNION
    SELECT
        year,
        'Au_open' AS tournament,
        Au_open AS winner
),
cte2 AS(
    SELECT
        player_id,
        COUNT(player_id) AS grand_slam_count
    FROM
        cte
    GROUP BY
        player_id
)
SELECT
    c.player_id,
    p.player_name,
    c.grand_slam_count
FROM
    cte2 c
    LEFT JOIN player p ON c.player_id = p.player_id