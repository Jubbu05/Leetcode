SELECT
    p.post_id,
    IFNULL(
        GROUP_CONCAT(
            DISTINCT k.topic_id
            ORDER BY
                k.topic_id
        ),
        'Ambiguous!'
    ) AS topic
FROM
    Posts p
    LEFT JOIN Keywords k ON CONCAT(' ', LOWER(p.content), ' ') LIKE CONCAT('% ', LOWER(k.word), ' %')
GROUP BY
    p.post_id