WITH RECCURSIVE cte as(
    SELECT * FROM Tasks
    UNION
    SELECT task_id, subtask_count - 1
    FROM cte
    WHERE subtask_count > 1
)

SELECT task_id, subtask_count AS subtask_id
FROM cte
WHERE (task_id, subtask_count) NOT IN (SELECT * FROM Executed)
ORDER BY task_id, subtask_count