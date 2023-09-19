SELECT DISTINCT(candidate_id)
FROM candidates
WHERE skill IN ('Python', 'Tableau', 'PostgreSQL')
GROUP BY 1 
HAVING COUNT(*) >= 3
ORDER BY 1;