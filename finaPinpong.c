remote: Counting objects: 100% (19/19), done.
remote: Compressing objects: 100% (13/13), done.
remote: Total 19 (delta 10), reused 8 (delta 6), pack-reused 0 (from 0)
Unpacking objects: 100% (19/19), 7.66 KiB | 1.28 MiB/s, done.
From ssh://git-ssh.21-school.ru:2222/students_repo/shinoher/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1
 * branch            develop    -> FETCH_HEAD
   92da47c..fe874ea  develop    -> origin/develop
hint: You have divergent branches and need to specify how to reconcile them.
hint: You can do so by running one of the following commands sometime before
hint: your next pull:
hint: 
hint:   git config pull.rebase false  # merge
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint: 
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
fatal: Need to specify how to reconcile divergent branches.
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ git status
On branch develop
nothing to commit, working tree clean
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ git config pull.rebase false
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ git pull origin develop
From ssh://git-ssh.21-school.ru:2222/students_repo/shinoher/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1
 * branch            develop    -> FETCH_HEAD
Auto-merging src/pong.c
CONFLICT (content): Merge conflict in src/pong.c
Automatic merge failed; fix conflicts and then commit the result.
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ 
