"""
Output of this program will look like this
[+] Enter Target/s to scan (split multiple targets with ,): 192.168.xx.xx
[-_0 Scanning Target] 192.168.xx.xx
[+] Open Port 22 : SSH-2.0-OpenSSH_8.2p1 Ubuntu-4ubuntu0.1
[+] Open Port 80
c
"""

import socket
from IPy import IP


def scan(target):
    converted_ip = check_ip(target)
    print(f'\n[-_0 Scanning Target] {target} \n')
    for port in range(0, 100):
        scan_port(converted_ip, port)


# To get the ip address if domain name is given
def check_ip(ip):
    try:
        IP(ip)
        return(ip)
    except ValueError:
        return socket.gethostbyname(ip)

def get_banner(s):
    return s.recv(1024)

# scan the port
def scan_port(ipaddress, port):
    try:
        sock = socket.socket()
        sock.settimeout(0.5)
        sock.connect((ipaddress, port))
        try:
            banner = get_banner(sock)
            print(f"[+] Open Port {port} : " + str(banner.decode().strip('\n')))
        except:
            print(f"[+] Open Port {port}")
    except:
        pass
 


if __name__ == "__main__":
    targets = input("[+] Enter Target/s to scan (split multiple targets with ,): ")
    if ',' in targets:
        for ip_add in targets.split(','):
            scan(ip_add.strip(' '))
    else:
        scan(targets)
