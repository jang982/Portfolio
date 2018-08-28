Shader "Custom/ColorChanger" {
	Properties{
		_Color1("Color1", Color) = (1,1,1,1)
		_Color2("Color2", Color) = (1,1,1,1)
		_Color3("Color3", Color) = (1,1,1,1)
		_MainTex ("Albedo (RGB)", 2D) = "white" {}
	}
		SubShader{
			Tags { "RenderType" = "Transparent" "Queue" = "Transparent" "IgnoreProjector" = "True" }
			Lighting Off
			ZWrite Off
			Blend Zero One

			CGPROGRAM
		#pragma surface surf NoLighting alpha

		float4 _Color1;
		float4 _Color2;
		float4 _Color3;
		sampler2D _MainTex;

		struct Input {
			float2 uv_MainTex;
		};

		void surf(Input IN, inout SurfaceOutput o) {
			fixed4 t = tex2D(_MainTex, IN.uv_MainTex);
			fixed dr = t.r - t.g; fixed dg = t.g - t.b; fixed db = t.r - t.b;
			if (dr < 0) dr = -dr; if (dg < 0) dg = -dg; if (db < 0) db = -db;

			if (t.r > 0.8f && t.g > 0.8f && t.b > 0.8f) o.Albedo = _Color3;
			else if (t.r == 0.0f && t.g == 0.0f && t.b == 0.0f) o.Albedo = _Color1;
			else if ( (dr + dg + db) < 0.05f) o.Albedo = _Color1;
			else o.Albedo = _Color2;

			o.Alpha = t.a;
		}
		half4 LightingNoLighting(SurfaceOutput s, half3 lightDir, half atten) {
			return half4(s.Albedo, s.Alpha);
		}
		ENDCG
	}
}
