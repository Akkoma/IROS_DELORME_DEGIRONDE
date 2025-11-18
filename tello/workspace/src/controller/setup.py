from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'action'), glob('action/*.action')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='alix.degironde',
    maintainer_email='alix.degironde@cpe.fr',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
             'manual_control = controller.manual_control:main',
             'tello_behaviour = controller.tello_behaviour:main',
             'spielberg = controller.spielberg:main',
             'surveillance = controller.surveillance:main',
             'qr_code_follower = controller.qr_code_follower:main',
             'qr_code_reader = controller.qr_code_reader:main'
        ],
    },
)
