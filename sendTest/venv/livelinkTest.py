import socket
import json
import time
import math
import json
# from scipy.spatial.transform import Rotation as R


def UDPconnectTest():

    BonesName = [
        "pelvis",
        "spine_01",
        "spine_02",
        "spine_03",
        "neck_01",
        "head",
        "clavicle_l",
        "upperarm_l",
        "lowerarm_l",
        "hand_l",
        "clavicle_r",
        "upperarm_r",
        "lowerarm_r",
        "hand_r",
        "thigh_r",
        "calf_r",
        "foot_r",
        "ball_r",
        "thigh_l",
        "calf_l",
        "foot_l",
        "ball_l",
    ]
    UDP_IP = '127.0.0.1'
    UDP_connect = 8010
    Buffer_size = 1024
    targetAddr = ('127.0.0.1', 8010)
    #Message = '{ "Frame1": { "pelvis": { "Position": [ 32.8062248, 69.9799957, -49.1268463 ] } } }'
    #Message = '{ "Frame1": { "pelvis": { "Position": [ 0, 0, 0], "Rotation": [ 0, 0,0, 0 ] }, "spine_01": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_02": { "Position": [ 0, 0,0], "Rotation": [ 0, 0, 0, 0 ] }, "spine_03": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_04": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "neck_01": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] } } }'
    Message = '{ "Frame": { "CurrentFrame": 1 }, "Bone": { "pelvis": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_01": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_02": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_03": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "spine_04": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] }, "neck_01": { "Position": [ 0, 0, 0 ], "Rotation": [ 0, 0, 0, 0 ] } } }'
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    FrameIndex = 1
    Postion_X = 0.0
    Postion_Y = 0.0
    Posetion_Z = 0.0
    Quat_X = 0.0
    Quat_Y = 0.0
    Quat_Z = 0.0
    Quat_W = 0.0

    while True:

        FrameIndex += 1
        Rotation_X = math.sin(FrameIndex) * 360
        Rotation_Y = math.sin(FrameIndex) * 30
        Rotation_Z = math.sin(FrameIndex) * 180.0

        Quat_X = math.sin(FrameIndex)

        Quat_Y = math.sin(FrameIndex)
        Quat_Z = math.sin(FrameIndex)
        Quat_W = math.sin(FrameIndex)
        # Quat_X = 0.0;
        # Quat_Y = 0.0
        # Quat_Z = 0.0
        # Quat_W = 0.0
        # Quat_Z = math.sin(FrameIndex)

        MessageObject = {
            "Frames": {"CurrentFrame": FrameIndex},
            "Bones": {
                # "root":{ "Position": [0.0,0.0,0.0 ], "Rotation": [ 0.0, 0.0 ,0.0,0.0] },
                # "pelvis":{ "Position": [-0.0,2.094849,87.070763 ], "Rotation": [ -0.135841325,0.2229019,0.930396438,-0.257341 ] },
                # "spine_01":{ "Position": [2.031172,-0.104403,-0.0 ], "Rotation": [ -0.135841325,0.2229019,0.930396438,-0.257341 ] },
                # "spine_03":{ "Position": [0.0,3.692248,99.983795 ], "Rotation": [  -0.228598714,0.788797,-0.121670052,-0.557439 ] },
                # "spine_05":{ "Position": [ 0.00026,-0.052704,122.554077 ], "Rotation": [-0.228598714,0.788797,-0.121670052,-0.557439 ] },
                # "neck_01":{ "Position": [0.000361,-2.047925,132.989441 ], "Rotation": [ -0.228598714,0.788797,-0.121670052,-0.557439 ] },
                # "head":{ "Position": [  0.000463,0.133269,143.358246 ], "Rotation": [   0.5966404,-0.358699143,0.4081047,-0.5905978 ] },

                # "clavicle_l":{ "Position": [0.816855,-1.885996,127.439514 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "upperarm_l":{ "Position": [15.784872,-0.0,0.0 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] }
                # "lowerarm_l":{ "Position": [28.497957,-1.541701,106.763359 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "hand_l":{ "Position": [40.075104,12.635607,92.892136 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },

                # "clavicle_r":{ "Position": [-0.815927,-1.885986,127.439484], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "upperarm_r":{ "Position": [-14.040407,-2.184497,125.705772], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "lowerarm_r":{ "Position": [-28.498146,-1.541674,106.763107], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "hand_r":{ "Position": [-40.075165,12.635484,92.892021 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },

                # "thigh_r":{ "Position": [-9.572074,2.311687,84.024788 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "calf_r":{ "Position": [ -11.452472,1.481148,43.834705], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "foot_r":{ "Position": [ -13.071536,0.067687 ,7.154362  ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "ball_r":{ "Position": [ -14.643463,11.726923,0.844502 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },

                # "thigh_l":{ "Position": [9.572069,2.31169,84.024811 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "calf_l":{ "Position": [11.452459,1.48115,43.834709], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "foot_l":{ "Position": [13.071524,0.067689,7.15435 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] },
                # "ball_l":{ "Position": [14.643486,11.726921,0.844491 ], "Rotation": [ Quat_X, Quat_Y, Quat_Z, Quat_W ] }
                # "root": {"Position": [0.0, 0.0, 0.0], "Rotation": [0.0, 0.0, 0.0, 0.0]},
                
                
                # "spine_01": {"Position": [2.031172, -0.104403, -0.0], "Rotation": [-0.0, -0.0, 10.958]},
                # "spine_03": {"Position": [6.75445, -0.0, 0.0], "Rotation": [0.0, -0.00, -9.506]},
                # "neck_01": {"Position": [10.62439, 0.0, 0.0], "Rotation": [-0.0, 0.0, 23.154]},


                # "pelvis": {"Position": [-0.0, 2.094849, 87.070763], "Rotation": [89.999901, 87.946991, 89.999901]},
                # "spine_03": {"Position": [15.03843, 0.0, 0.0], "Rotation": [0.0, 0.0, 0.0]},
                # "head": {"Position": [5.279529, -0.0, -0.0], "Rotation": [0,0,-11.425723]},

                # "clavicle_l":{ "Position": [5.142807,-0.883206,-0.816548 ], "Rotation": [ 0, 0, 0 ] },
                # "upperarm_l":{ "Position": [13.34004,-0.0,0.0 ], "Rotation": [0, 0, 0 ] },
                # "lowerarm_l":{ "Position": [23.837999,0.0,0.0 ], "Rotation": [ 0, 0, 0 ] },
                # "hand_l":{ "Position": [22.966,0,0 ], "Rotation": [ 0, 0, 0 ] },

                # "clavicle_r":{ "Position": [5.142765,-0.883,0.816], "Rotation": [ 0, 0, 0 ] },
                # "upperarm_r":{ "Position": [-13.34098,0.00,-0.00], "Rotation": [ 0, 0, 0 ] },
                # "lowerarm_r":{ "Position": [-23.838289,0.0,0.0], "Rotation": [ 0, 0, 0 ] },
                # "hand_r":{ "Position": [-22.965759,-0.0,0.0 ], "Rotation": [ 0, 0, 0 ] },

                # "thigh_l":{ "Position": [-3.036232,0.326,9.572 ], "Rotation": [ 0, 0, 0 ] },
                # "calf_l":{ "Position": [-40.242619,-0.0,0.0], "Rotation": [ 0, 0, 0 ] },
                # "foot_l":{ "Position": [-6.743259,-0.0 ,-0.0  ], "Rotation": [ 0, 0, 0 ] },
                
                # "thigh_r":{ "Position": [-3.036256,0.326,9.572 ], "Rotation": [ 0, 0, 0 ] },
                # "calf_r":{ "Position": [ 40.242619,-0.0,0.0], "Rotation": [ 0, 0, 0 ] },
                # "foot_r":{ "Position": [ 36.743259,-0.0 ,-0.0  ], "Rotation": [ 0, 0, 0 ] },


                # "ball_l":{ "Position": [-5.935503,-11.957,-0.1724 ], "Rotation": [ 0, 0, 0 ] }
                "spine_01": {"Position": [-0.0, 2.0, 0.070763], "Rotation": [0, 0, 0]},
                "spine_03": {"Position": [0, 0.0, 0.0], "Rotation": [0.0, -0.00, -9.506]},
                "head": {"Position": [0, -0.0, -0.0], "Rotation": [0,0,-11.425723]},

                "clavicle_l":{ "Position": [0,-0.883206,-0.816548 ], "Rotation": [ -61, -101 ,108.71917  ] },
                "upperarm_l":{ "Position": [0,-0.0,0.0 ], "Rotation": [Rotation_X, 0, 0 ] },
                "lowerarm_l":{ "Position": [0,0.0,0.0 ], "Rotation": [ Rotation_X, 0, 0 ] },
                "hand_l":{ "Position": [0,0,0 ], "Rotation": [ Rotation_X, 0, 0 ] },

                "clavicle_r":{ "Position": [0,-0.883,0.816], "Rotation": [  -61, 78 ,108.71917] },
                "upperarm_r":{ "Position": [0,0.00,-0.00], "Rotation": [ Rotation_X, 0, 0 ] },
                "lowerarm_r":{ "Position": [0,0.0,0.0], "Rotation": [ Rotation_X, 0, 0 ] },
                "hand_r":{ "Position": [0,-0.0,0.0 ], "Rotation": [ Rotation_X, 0, 0 ] },

                "thigh_l":{ "Position": [0,0.326,9.572 ], "Rotation": [ 0,0,0 ] },
                "calf_l":{ "Position": [0,-0.0,0.0], "Rotation": [ 0, Rotation_Y, 0 ] },
                "foot_l":{ "Position": [0,-0.0 ,-0.0  ], "Rotation": [ 0, 0, 0 ] },
            
                "thigh_r":{ "Position": [-0,0.326,9.572 ], "Rotation": [ 0, 180, 0 ] },
                "calf_r":{ "Position": [ 0,-0.0,0.0], "Rotation": [ 0, -Rotation_Y, 0 ] },
                "foot_r":{ "Position": [ 0,-0.0 ,-0.0  ], "Rotation": [ 0, 0, 0 ] }
                # "ball_l":{ "Position": [-5.935503,-11.957,-0.1724 ], "Rotation": [ 0, 0, 0 ] }
                # "ball_r":{ "Position": [ 5.935503,-11.957,-0.1724 ], "Rotation": [ 0, 0, 0 ] },

                
                # "upperarm_l": {"Position": [15.784872, -0.0, 0.0], "Rotation": [Rotation_X, 0, 0]}

            }
        }
        # print(str(MessageObject))
        # s.sendto(str(MessageObject).encode('utf8'),targetAddr)
        temp = json.dumps(MessageObject)
        time.sleep(0.2)
        print(temp)
        s.sendto(temp.encode('utf8'), targetAddr)


def Reduce_JsonData(fillpath):

    f = open(fillpath, 'r')
    m = json.load(f)
    print(m["Frame1"])
    f.close()
    f1 = open('E:/LiveLinkSendTest/venv/LiveLinkData.json', 'w')
    for i in range(1, 10):
        keyIndex = "Frame"+str(i)
        f1.write(json.dumps(m[keyIndex]))
    f1.close()


if __name__ == '__main__':
    UDPconnectTest()

    #    Reduce_JsonData('E:/LiveLinkSendTest/venv/walkAround.json')
