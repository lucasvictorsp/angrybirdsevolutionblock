using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public enum MATERIALS {
	wood , 
	stone , 
	ice
};

public enum BIRDS  { 
	Red , 
	Green , 
	Blue 
};

public enum PIGS   { 
	BasicSmall , 
	BasicMedium , 
	BasicLarge 
};

public enum BLOCKS { 
	Circle , 
	CircleSmall ,
    RectBigLying ,
    RectBigStanding ,
    RectFatLying ,
    RectFatStanding ,
    RectMediumLying ,
    RectMediumStanding ,
    RectSmallLying ,
    RectSmallStanding ,
    RectTinyLying ,
    RectTinyStanding ,
    SquareHole , 
	SquareSmall ,
	SquareTiny ,
	Triangle ,
	TriangleHole ,
    TriangleMirror
};

public enum SLINGSHOT_LINE_POS
{
	SLING ,
	BIRD
};

/*
Circle id= 0 x= -0.17 y= 0.375 , x= -0.38 y= 0.155 , x= -0.38 y= -0.155 , x= -0.17 y= -0.375, x= 0.17 y= -0.375 , x= 0.38 y= -0.155, x= 0.38  y= 0.155 , x= 0.17 y= 0.375 .
CircleSmall id= 1 x= -0.09129941 y= 0.2039118 , x= -0.2099999 y= 0.05912399 , x= -0.197825 y= -0.07564354 , x= 0.11 y= -0.21 , x= 0.06347454 y= -0.2069559 , x= 0.2008685 y= -0.09000015 , x= 0.2008686 y= 0.09912491 , x= 0.05956221 y= 0.2039118 . 
RectBigLying id= 2 x= -2.06 y= 0.22 , x= -2.06 y= -0.22 , x= 2.06 y= -0.22 , x= 2.06 y= 0.22 .
RectBigStanding id= 3 x= -0.22 y= 2.06 , x= -0.22 y= -2.06 , x= 0.22 y= -2.06 , x= 0.22 y= 2.06 .
RectFatLying id= 4 x= -0.85 y= 0.43 x= -0.85 y= -0.43 , x= 0.85 y= -0.43, x= 0.85 y= 0.43 .
RectFatStanding id= 5 x= -0.43 y= 0.85 , x= -0.43 y= -0.85 , x= 0.43 y= -0.85 , x= 0.43 y= 0.85 .
RectMediumLying id= 6 x= -1.68 y= 0.22 , x= -1.68 y= -0.22, x= 1.68 y= -0.22 , x= 1.68 y= 0.22 .
RectMediumStanding id= 7 x= -0.22 y= 1.68 , x= -0.22 y= -1.68 , x= 0.22 y= -1.68 , x= 0.22 y= 1.68 . 
RectSmallLying id= 8 x= -0.85 y= 0.22 , x= -0.85 y= -0.22 , x= 0.85 y= -0.22 , x= 0.85 y= 0.22 .
RectSmallStanding id= 9 x= -0.22 y= 0.85 , x= -0.22 y= -0.85 , x= 0.22 y= -0.85 , x= 0.22 y= 0.85 . 
RectTinyLying id= 10 x= -0.43 y= 0.22 , x= -0.43 y= -0.22 , x= 0.43 y= -0.22 , x= 0.43 y= 0.22 . 
RectTinyStanding id= 11 x= -0.22 y= 0.43 , x= -0.22 y= -0.43 , x= 0.22 y= -0.43 , x= 0.22 y= 0.43 . 
SquareHole id= 12 x= -0.84 y= 0.84 , x= -0.84 y= -0.84 , x= 0.84 y= -0.84 , x= 0.84 y= 0.84 . 
SquareSmall id= 13 x= -0.43 y= 0.43 , x= -0.43 y= -0.43 ,  x= 0.43 y= -0.43 , x= 0.43 y= 0.43 .
SquareTiny id= 14 x= -0.22 y= 0.21 , x= -0.22 y= -0.21 , x= 0.22 y= -0.21 , x= 0.22 y= 0.21 . 
Triangle id= 15 x= -0.41 y= 0.4 , x= -0.41 y= -0.4 , x= 0.41 y= -0.4 . 
TriangleMirror id= 16 x= -0.41 y= -0.4 , x= 0.41 y= -0.4 , x= 0.41 y= 0.4 .
TriangleHole id= 17 x= -0.0002177209 y= 0.42 , x= -0.4257719 y= -0.42 ,  x= 0.4257719 y= -0.42 .

Plataform id= 18 x= -0.64 y= 0.64 , x= -0.64 y= -0.64 , x= 0.64 y= -0.64 , x= 0.64, y= 0.64 .
//*/

public class ABConstants {

	public static readonly Vector3 SLING_SELECT_POS = new Vector3 (-7.62f, -1.24f, 1f);
}

public class ABWorldAssets {

	public static readonly GameObject[] WOOD_DESTRUCTION_EFFECT  = Resources.LoadAll<GameObject>("Prefabs/GameWorld/Particles/Wood");
	public static readonly GameObject[] STONE_DESTRUCTION_EFFECT = Resources.LoadAll<GameObject>("Prefabs/GameWorld/Particles/Stone");
	public static readonly GameObject[] ICE_DESTRUCTION_EFFECT   = Resources.LoadAll<GameObject>("Prefabs/GameWorld/Particles/Stone");

	public static readonly Dictionary<string, GameObject> BIRDS = LevelLoader.LoadABResource ("Prefabs/GameWorld/Characters/Birds");
	public static readonly Dictionary<string, GameObject> PIGS = LevelLoader.LoadABResource ("Prefabs/GameWorld/Characters/Pigs");
	public static readonly Dictionary<string, GameObject> BLOCKS = LevelLoader.LoadABResource ("Prefabs/GameWorld/Blocks");

	public static readonly GameObject PLATFORM = (GameObject) Resources.Load ("Prefabs/GameWorld/Platform");
	public static readonly GameObject SCORE_POINT = (GameObject) Resources.Load ("Prefabs/GameWorld/ScorePoints");

	public static readonly AudioClip[] WOOD_DAMAGE_CLIP  = Resources.LoadAll<AudioClip>("Audio/Blocks/Wood");
	public static readonly AudioClip[] STONE_DAMAGE_CLIP = Resources.LoadAll<AudioClip>("Audio/Blocks/Stone");
	public static readonly AudioClip[] ICE_DAMAGE_CLIP   = Resources.LoadAll<AudioClip>("Audio/Blocks/Stone");

	public static readonly PhysicsMaterial2D WOOD_MATERIAL  = Resources.Load("Materials/Wood") as PhysicsMaterial2D;
	public static readonly PhysicsMaterial2D STONE_MATERIAL = Resources.Load("Materials/Stone") as PhysicsMaterial2D;
	public static readonly PhysicsMaterial2D ICE_MATERIAL   = Resources.Load("Materials/Ice") as PhysicsMaterial2D;
}
