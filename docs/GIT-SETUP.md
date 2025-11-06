GIT Setup and remote notes
=========================

This repository was configured locally and pushed to the GitHub repository
`https://github.com/Davi-Mendes23/UEPA-Projetos.git`.

What I did:

- Updated the local `origin` remote to point at the `UEPA-Projetos` repo.
- Pulled remote commits and rebased local commits on top to avoid history conflicts.
- Pushed local changes so `main` now tracks `origin/main`.

Switching to SSH (optional but recommended if you prefer SSH auth):

1. Make sure you have an SSH key locally (check `~/.ssh/id_rsa.pub` or `id_ed25519.pub`).
2. Add the public key to your GitHub account: https://github.com/settings/keys
3. Change the remote to the SSH URL:

   git remote set-url origin git@github.com:Davi-Mendes23/UEPA-Projetos.git

4. Verify with:

   git remote -v

Notes
-----
- If you change to SSH and your key isn't loaded, pushes will fail until the key is added to the agent or Windows SSH is configured.
- To undo remote changes and point back to HTTPS use:

   git remote set-url origin https://github.com/Davi-Mendes23/UEPA-Projetos.git

Contact
-------
If you want me to switch the remote to SSH now, tell me and I'll run the command.
