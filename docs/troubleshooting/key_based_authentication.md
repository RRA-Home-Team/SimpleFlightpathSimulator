# Key-based authentication for Github

Alternatively, read the [official documentation](https://help.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh).

## **Motivation**
Using a [secure shell (SSH)](https://en.wikipedia.org/wiki/Secure_Shell) allows you to issue encrypted commands to github and it avoids the need for you to repeatedy enter your github login credentials.

## **Generate a public/private rsa key pair**
Issue the following command inside a git-bash terminal using the email address associated with your github account:
```bash
ssh-keygen -t rsa -b 4096 -C "email@gmail.com"
```
<details>
<summary>Notes...</summary>

This command generates a public/private rsa key pair in your `~/.ssh` (likely `C:\Users\%user%\.ssh` on windows) directory the using the [ssh-keygen](https://en.wikipedia.org/wiki/Ssh-keygen) command.  The arguments are as follows:
1. ```t``` - specifies the type of cryptography = RSA
2. ```b``` - specifies the number of bits in the output key = 4096 (bits)
3. ```C``` - specifies a comment which gets appended to key fingerprint = user email for github

The ssh-keygen tool asks for a passphrase which is used as a seed to generate the key.  Running the command should produce two files;
- a private key for decryption - `~/.ssh/id_rsa`:
  ```
  -----BEGIN OPENSSH PRIVATE KEY-----
  b3BlbnNzaC1...tYWlsLmNvbQEC
  -----END OPENSSH PRIVATE KEY-----
  ```
- a public key for data encryption - `~/.ssh/id_rsa.pub`:
  ```
  ssh-rsa AAAAB3N...Q+R9ALKw== email@gmail.com
  ```

</details>

## **Create a Secure Connection to Github**

```bash
# - Generate Bourne (s)hell commands on stdout
eval $(ssh-agent -s)
```

... and add the private ssh key to from the folder
```bash
ssh-add ~/.ssh/id_rsa
```
<details>
<summary>Notes...</summary>
create a [socket](https://en.wikipedia.org/wiki/Network_socket) allowing secure remote login using public-key cryptography. *Note that the [eval](https://en.wikipedia.org/wiki/Eval#Unix_shells) command simply executes the output from the command string output by the [ssh-agent](https://en.wikipedia.org/wiki/Ssh-agent) command*.


</details>

## **Add private key to github**

![Github settings - SSH and GPG keys page](./SSH_and_GPG_keys.gif)

<details>
<summary>Notes...</summary>

You can copy the *public* shh key to the clipboard using the following command...
```bash
clip < ~/.ssh/id_rsa.pub
```

Finally, open the settings for your github acount (accessible from the dropdown menu when cicking on your profie picture).  Swich to the *SSH and GPG keys* page and create a new SSH key using the public key you previously generated.

</details>
---

## **Troubleshooting**

<details>

<summary><span style="font-size:larger;"><strong>Push or Pull fails with</strong></span></br>
<span style="color:yellow;">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ssh: connect to host github.com port 22: Network is unreachable </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fatal: Could not read from remote repository. ... </br>
</summary>
</span>

### First Try Unblocking the Port
If you get this issue you need to enable the port on your router.  Get the router's IP address by Reading the **Default Gateway** from an ```ipconfig ``` command.  Mines was *192.168.0.1* - stick this in the address bar of your browser to access the router settings.  Enable port 22 from there.  Also check ```netstat -a``` to see which ports are blocked.

### Redirect SSH to an Alternative Port
Finally, your ISP might block the port altogether.  I got this issue straight after I got my new [Virgin Media 3.0](https://www.youtube.com/watch?v=WFzSKut0jO4) installed - previously I'd been tethering from my phone.

create the file *~/.ssh/config* and enter the following:
```
Host github.com
 Hostname ssh.github.com
 Port 2222
```
</details>
