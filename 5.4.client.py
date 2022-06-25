from netmiko import ConnectHandler

myserver = {
    'device_type': 'linux',
    'host':   '192.168.53.3',  #Your Server IP
    'username': 'nuna', #your Server Username
    'password': 'nuna9679', #your server password
    'port' : 22,
    'secret': '',
}

net_connect = ConnectHandler(**myserver)
output = net_connect.send_command('apt-get update')
print(output)

