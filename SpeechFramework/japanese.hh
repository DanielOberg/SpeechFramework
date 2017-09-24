//
//  japanese.h
//  SpellingBee
//
//  Created by Daniel Oberg on 2015-12-01.
//  Copyright © 2015 United Lambdas. All rights reserved.
//

#ifndef japanese_h
#define japanese_h

#include <map>
#include <vector>
#include <string>

const std::map<const std::string, const std::string> romajiToHiragana {
    {"a","あ"},
    {"ka","か"},
    {"sa","さ"},
    {"ta","た"},
    {"na","な"},
    {"i","い"},
    {"ki","き"},
    {"shi","し"},
    {"chi","ち"},
    {"ni","に"},
    {"u","う"},
    {"ku","く"},
    {"su","す"},
    {"tsu","つ"},
    {"nu","ぬ"},
    {"e","え"},
    {"ke","け"},
    {"se","せ"},
    {"te","て"},
    {"ne","ね"},
    {"o","お"},
    {"ko","こ"},
    {"so","そ"},
    {"to","と"},
    {"no","の"},
    {"ha","は"},
    {"ma","ま"},
    {"ya","や"},
    {"ra","ら"},
    {"wa","わ"},
    {"hi","ひ"},
    {"mi","み"},
    {"ri","り"},
    {"wi","ゐ"},
    {"fu","ふ"},
    {"mu","む"},
    {"yu","ゆ"},
    {"ru","る"},
    {"n","ん"},
    {"he","へ"},
    {"me","め"},
    {"re","れ"},
    {"we","ゑ"},
    {"ho","ほ"},
    {"mo","も"},
    {"yo","よ"},
    {"ro","ろ"},
    {"wo","を"},
    {"ga","が"},
    {"za","ざ"},
    {"da","だ"},
    {"ba","ば"},
    {"pa","ぱ"},
    {"gi","ぎ"},
    {"ji","じ"},
    {"ji","ぢ"},
    {"bi","び"},
    {"pi","ぴ"},
    {"gu","ぐ"},
    {"zu","ず"},
    {"zu","づ"},
    {"bu","ぶ"},
    {"pu","ぷ"},
    {"ge","げ"},
    {"ze","ぜ"},
    {"de","で"},
    {"be","べ"},
    {"pe","ぺ"},
    {"go","ご"},
    {"zo","ぞ"},
    {"do","ど"},
    {"bo","ぼ"},
    {"po","ぽ"},
    {"kya","きゃ"},
    {"sha","しゃ"},
    {"cha","ちゃ"},
    {"hya","ひゃ"},
    {"pya","ぴゃ"},
    {"kyu","きゅ"},
    {"shu","しゅ"},
    {"chu","ちゅ"},
    {"hyu","ひゅ"},
    {"pyu","ぴゅ"},
    {"kyo","きょ"},
    {"sho","しょ"},
    {"cho","ちょ"},
    {"hyo","ひょ"},
    {"pyo","ぴょ"},
    {"gya","ぎゃ"},
    {"ja","じゃ"},
    {"nya","にゃ"},
    {"bya","びゃ"},
    {"mya","みゃ"},
    {"ju","じゅ"},
    {"nyu","にゅ"},
    {"byu","びゅ"},
    {"myu","みゅ"},
    {"gyu","ぎゅ"},
    {"gyo","ぎょ"},
    {"jo","じょ"},
    {"nyo","にょ"},
    {"byo","びょ"},
    {"myo","みょ"},
    {"rya","りゃ"},
    {"ryu","りゅ"},
    {"ryo","りょ"},
    {"xtsu","っ"}
};

const std::map<const std::string, const std::string> romajiToKatakana {
    {"a","ア"},
    {"ka","カ"},
    {"sa","サ"},
    {"ta","タ"},
    {"na","ナ"},
    {"i","イ"},
    {"ki","キ"},
    {"shi","シ"},
    {"chi","チ"},
    {"ni","ニ"},
    {"u","ウ"},
    {"ku","ク"},
    {"su","ス"},
    {"tsu","ツ"},
    {"nu","ヌ"},
    {"e","エ"},
    {"ke","ケ"},
    {"se","セ"},
    {"te","テ"},
    {"ne","ネ"},
    {"o","オ"},
    {"ko","コ"},
    {"so","ソ"},
    {"to","ト"},
    {"no","ノ"},
    {"ha","ハ"},
    {"ma","マ"},
    {"ya","ヤ"},
    {"ra","ラ"},
    {"wa","ワ"},
    {"hi","ヒ"},
    {"mi","ミ"},
    {"ri","リ"},
    {"fu","フ"},
    {"mu","ム"},
    {"yu","ユ"},
    {"ru","ル"},
    {"n","ン"},
    {"he","ヘ"},
    {"me","メ"},
    {"re","レ"},
    {"ho","ホ"},
    {"mo","モ"},
    {"yo","ヨ"},
    {"ro","ロ"},
    {"ga","ガ"},
    {"za","ザ"},
    {"da","ダ"},
    {"ba","バ"},
    {"pa","パ"},
    {"gi","ギ"},
    {"ji","ジ"},
    {"ji","ヂ"},
    {"bi","ビ"},
    {"pi","ピ"},
    {"gu","グ"},
    {"zu","ズ"},
    {"zu","ヅ"},
    {"bu","ブ"},
    {"pu","プ"},
    {"ge","ゲ"},
    {"ze","ゼ"},
    {"de","デ"},
    {"be","ベ"},
    {"pe","ペ"},
    {"go","ゴ"},
    {"zo","ゾ"},
    {"do","ド"},
    {"bo","ボ"},
    {"po","ポ"},
    {"kya","キャ"},
    {"sha","シャ"},
    {"cha","チャ"},
    {"hya","ヒャ"},
    {"pya","ピャ"},
    {"kyu","キュ"},
    {"shu","シュ"},
    {"chu","チュ"},
    {"hyu","ヒュ"},
    {"pyu","ピュ"},
    {"kyo","キョ"},
    {"sho","ショ"},
    {"cho","チョ"},
    {"hyo","ヒョ"},
    {"pyo","ピョ"},
    {"gya","ギャ"},
    {"ja","ジャ"},
    {"nya","ニャ"},
    {"bya","ビャ"},
    {"mya","ミャ"},
    {"gyu","ギュ"},
    {"ju","ジュ"},
    {"nyu","ニュ"},
    {"byu","ビュ"},
    {"my","ミュ"},
    {"gyo","ギョ"},
    {"jo","ジョ"},
    {"nyo","ニョ"},
    {"byo","ビョ"},
    {"myo","ミョ"},
    {"rya","リャ"},
    {"ryu","リュ"},
    {"ryo","リョ"},
    {"ye","イェ"},
    {"va","(ヷ)"},
    {"va","ヴァ"},
    {"she","シェ"},
    {"wi","ウィ"},
    {"vi","ヴィ"},
    {"je","ジェ"},
    {"we","ウェ"},
    {"vu","ヴ"},
    {"ve","ヴェ"},
    {"che","チェ"},
    {"wo","ウォ"},
    {"vo","ヴォ"},
    {"vya","ヴャ"},
    {"ti","ティ"},
    {"tsa","ツァ"},
    {"fa","ファ"},
    {"tu","トゥ"},
    {"tsi","ツィ"},
    {"fi","フィ"},
    {"tyu","テュ"},
    {"tse","ツェ"},
    {"fe","フェ"},
    {"di","ディ"},
    {"tso","ツォ"},
    {"fo","フォ"},
    {"du","ドゥ"},
    {"fyu","フュ"},
    {"dyu","デュ"},
    {"xtsu","ッ"},
    {"dash","ー"},
    {"xxx","xxx"} // noise
};


struct JapaneseWord {
    std::string hiragana;
    std::string kanji;
    std::string explanation;
    std::string romaji;
};

std::vector<JapaneseWord> japaneseWords = {
{"オオカミ", "狼", "wolf", "ōokami"},
{"おちゃ", "お茶", "green tea ", "ocha"},
{"にんげん", "人間 ", "human being", "ningen"},
{"ぎゅうにゅう", "牛乳", "milk ", "gyūnyū"},
{"まぐろ", "鮪 ", "tuna", "maguro"},
{"およぐ", "泳ぐ ", "to swim", "oyogu"},
{"いぬ", "犬 ", "dog", "inu"},
{"コーヒー", "珈琲", "coffee ", "kōhī"},
{"やさい", "野菜", "vegetable", "yasai"},
{"りょうしん", "両親", "parents", "ryoushin"},
{"おっと", "夫 ", "husband", "otto"},
{"じんるい", "人類", "humanity", "jinrui"},
{"ひと", "人", "person", "hito"},
{"おとこ", "男", "male", "otoko"},
{"りゅう", "竜", "dragon", "ryū, tatsu"},
{"おとこのひと", "男の人 ", "man", "otokonohito"},
{"あかちゃん", "赤ちゃん ", "baby", "akachan"},
{"おとこのこ", "男の子 ", "boy", "otokonoko"},
{"わたし", "私 ", "I, myself", "watashi"},
{"おんな", "女 ", "female", "onna"},
{"おんなのひと", "女の人 ", "woman", "onnanohito"},
{"おんなのこ", "女の子 ", "girl", "onnanoko"},
{"わかもの", "若者 ", "youth, young person", "wakamono"},
{"いしゃ", "医者 ", "doctor", "isha"},
{"かんごし", "看護師 ", "nurse", "kangoshi"},
{"かんごふ", "看護婦 ", "female nurse", "kangofu"},
{"しかい", "歯科医", "dentist", "shikai"},
{"せいじか", "政治家 ", "politician", "seijika"},
{"べんごし", "弁護士 ", "lawyer", "bengoshi"},
{"しょうぼうし", "消防士 ", "firefighter", "shouboushi"},
{"けいさつかん", "警察官 ", "police officer", "keisatsukan"},
{"へいし", "兵士 ", "soldier", "heishi"},
{"けんちくか", "建築家 ", "architect", "kenchikuka"},
{"せんせい", "先生 ", "teacher", "sensei"},
{"かしゅ", "歌手 ", "singer", "kashu"},
{"あし", "足、脚 ", "foot, leg", "ashi"},
{"かかと", "踵 ", "heel", "kakato"},
{"すね", "脛 ", "shin", "sune"},
{"ひざ", "膝 ", "knee", "hiza"},
{"もも", "腿 ", "thigh", "momo"},
{"あたま", "頭 ", "head", "atama"},
{"かお", "顔 ", "face", "kao"},
{"くち", "口 ", "mouth", "kuchi"},
{"くちびる", "唇 ", "lips", "kuchibiru"},
{"は", "歯 ", "tooth", "ha"},
{"はな", "鼻 ", "nose", "hana"},
{"ひげ", "髭、鬚、髯 ", "moustache, beard", "hige"},
{"かみ", "髪 ", "hair", "kami"},
{"みみ", "耳 ", "ear", "mimi"},
{"い", "胃 ", "stomach", "i"},
{"うで", "腕 ", "arm", "ude"},
{"ひじ", "肘 ", "elbow", "hiji"},
{"かた", "肩 ", "shoulder", "kata"},
{"つめ", "爪 ", "nail", "tsume"},
{"て", "手 ", "hand", "te"},
{"てくび", "手首 ", "wrist", "tekubi"},
{"てのひら", "掌、手の平 ", "palm of hand", "te-no-hira"},
{"ゆび", "指 ", "finger, toe", "yubi"},
{"しり", "尻 ", "buttocks", "shiri"},
{"おなか", "お腹 ", "abdomen", "o-naka"},
{"かんぞう", "肝臓 ", "liver", "kanzō"},
{"きも", "肝 ", "liver", "kimo"},
{"きんにく", "筋肉 ", "muscle", "kin'niku"},
{"くび", "首 ", "neck", "kubi"},
{"こころ", "心 ", "heart [as in feelings]", "kokoro"},
{"こし", "腰 ", "waist, hip", "koshi"},
{"しんぞう", "心臓 ", "heart", "shinzō"},
{"せなか", "背中 ", "back", "senaka"},
{"ち", "血 ", "blood", "chi"},
{"にく", "肉 ", "meat", "niku"},
{"はだ", "肌 ", "skin", "hada"},
{"ひふ", "皮膚 ", "skin", "hifu"},
{"ほね", "骨 ", "bone", "hone"},
{"むね", "胸 ", "chest", "mune"},
{"かぜ", "風邪 ", "cold [illness]", "kaze"},
{"げり", "下痢 ", "diarrhea", "geri"},
{"びょうき", "病気 ", "illness", "byōki"},
{"かぞく", "家族 ", "family", "kazoku"},
{"こども", "子供 ", "children, child", "kodomo"},
{"ちち", "父 ", "father", "chichi"},
{"はは", "母 ", "mother", "haha"},
{"つま", "妻 ", "wife", "tsuma"},
{"あに", "兄 ", "older brother", "ani"},
{"あね", "姉 ", "older sister", "ane"},
{"おとうと", "弟 ", "younger brother", "otōto"},
{"いもうと", "妹 ", "younger sister", "imōto"},
{"きょうだい", "兄弟 ", "brothers, siblings", "kyōdai"},
{"しまい", "姉妹 ", "sisters", "shimai"},
{"そふ", "祖父 ", "grandfather", "sofu"},
{"そぼ", "祖母 ", "grandmother", "sobo"},
{"まご", "孫 ", "grandchild", "mago"},
{"おじ", "伯父 ", "uncle", "oji"},
{"おば", "伯母 ", "aunt", "oba"},
{"いとこ", "従兄弟 ", "cousin", "itoko"},
{"めい", "姪 ", "niece", "mei"},
{"おい", "甥 ", "nephew", "oi"},
{"いきもの", "生き物 ", "living creatures", "ikimono"},
{"ばけもの", "化け物 ", "monster", "bakemono"},
{"どうぶつ", "動物 ", "animal", "dōbutsu"},
{"ねこ", "猫 ", "cat", "neko"},
{"うし", "牛 ", "cow", "ushi"},
{"ぶた", "豚 ", "pig", "buta"},
{"うま", "馬 ", "horse", "uma"},
{"ひつじ", "羊 ", "sheep", "hitsuji"},
{"さる", "猿 ", "monkey", "saru"},
{"ねずみ", "鼠 ", "mouse, rat", "nezumi"},
{"とら", "虎 ", "tiger", "tora"},
{"うさぎ", "兎 ", "rabbit", "usagi"},
{"しか", "鹿 ", "deer", "shika"},
{"かえる", "蛙 ", "frog", "kaeru"},
{"がま", "蟇 ", "toad", "gama"},
{"しし", "獅子 ", "lion", "Shishi"},
{"キリン", "麒麟 ", "giraffe", "kirin"},
{"ぞう", "象 ", "elephant", "zō"},
{"とり", "鳥 ", "bird", "tori"},
{"にわとり", "鶏 ", "chicken", "niwatori"},
{"すずめ", "雀 ", "sparrow", "suzume"},
{"からす", "烏 ", "crow, raven", "karasu"},
{"わし", "鷲 ", "eagle", "washi"},
{"たか", "鷹 ", "hawk, falcon", "taka"},
{"さかな", "魚 ", "fish", "sakana"},
{"たい", "鯛 ", "red snapper", "tai"},
{"えび", "海老 ", "shrimp, lobster", "ebi"},
{"いわし", "鰯 ", "sardine", "iwashi"},
{"かつお", "鰹 ", "bonito", "katsuo"},
{"さんま", "秋刀魚 ", "pike", "sanma"},
{"あじ", "鰺 ", "horse mackerel", "aji"},
{"さば", "鯖 ", "mackerel", "saba"},
{"イカ", "烏賊 ", "squid", "ika"},
{"タコ", "蛸、章魚 ", "octopus", "tako"},
{"むし", "虫 ", "insect", "mushi"},
{"ちょう", "蝶 ", "butterfly", "chō"},
{"ガ", "蛾 ", "moth", "ga"},
{"せみ", "蝉 ", "cicada", "semi"},
{"トンボ", "蜻蛉 ", "dragonfly", "tonbo"},
{"バッタ", "飛蝗 ", "grasshopper", "batta"},
{"クモ", "蜘蛛 ", "spider", "kumo"},
{"ホタル", "蛍 ", "firefly", "hotaru"},
{"ハエ", "蝿、蠅 ", "housefly", "hae"},
{"カ", "蚊 ", "mosquito, gnat", "ka"},
{"ゴキブリ", "蜚蠊 ", "cockroach", "gokiburi"},
{"カタツムリ", "蝸牛 ", "snail", "katatsumuri"},
{"ナメクジ", "蛞蝓 ", "slug", "namekuji"},
{"ミミズ", "蚯蚓 ", "earthworm", "mimizu"},
{"かい", "貝 ", "shellfish", "kai"},
{"かいがら", "貝殻 ", "shell", "kaigara"},
{"トカゲ", "蜥蜴 ", "lizard", "tokage"},
{"へび", "蛇 ", "snake", "hebi"},
{"しょくぶつ", "植物", "plants ", "shokubutsu"},
{"くさ", "草", "grass ", "kusa, Shibafu"},
{"はな", "花", "flower ", "hana"},
{"み", "実", "fruit ", "mi"},
{"き", "木", "tree ", "ki"},
{"くき", "茎", "stem ", "kuki"},
{"きのこ", "茸", "mushroom ", "kinoko"},
{"きく", "菊", "chrysanthemum ", "kiku"},
{"さくら", "桜", "cherry blossom ", "sakura"},
{"こめ", "米 ", "uncooked rice", "kome"},
{"いね", "稲 ", "rice growing in a field", "ine"},
{"むぎ", "麦 ", "wheat, barley, oats", "mugi"},
{"くだもの", "果物 ", "fruit for eating", "kudamono"},
{"いも", "芋 ", "yam, potato, taro", "imo"},
{"まめ", "豆 ", "beans, peas", "mame"},
{"だいこん", "大根 ", "Japanese white radish", "daikon"},
{"にんじん", "人参 ", "carrot", "ninjin"},
{"リンゴ", "林檎 ", "apple", "ringo"},
{"ミカン", "蜜柑 ", "mandarin orange", "mikan"},
{"バナナ", "かんしょう、甘蕉 ", "banana", "banana, kanshō"},
{"ナシ", "梨 ", "pear", "nashi"},
{"クリ", "栗 ", "chestnut tree", "kuri"},
{"モモ", "桃 ", "peach", "momo"},
{"トマト", "ばんか、蕃茄 ", "tomato", "tomato, banka"},
{"スイカ", "西瓜 ", "watermelon", "suika"},
{"たべもの", "食べ物", "food ", "tabemono"},
{"ちょうしょく", "朝食", "breakfast ", "chōshoku, asagohan"},
{"ひるごはん", "昼御飯", "lunch ", "hirugohan"},
{"ばんごはん", "晩御飯", "supper ", "bangohan"},
{"ごはん", "御飯", "cooked rice or food ", "gohan"},
{"みそ", "味噌", "miso ", "miso"},
{"りょうり", "料理", "cooking ", "ryōri"},
{"おやつ", "間食", "snack ", "oyatsu"},
{"のみもの", "飲み物", "drink/beverage ", "nomimono"},
{"さとう", "砂糖", "sugar ", "satō"},
{"しお", "塩", "salt ", "shio"},
{"しょうゆ", "醤油", "soy sauce ", "shōyu"},
{"じかん", "時間 ", "time", "jikan"},
{"とき", "じ、時 ", "~hours", "toki, ji"},
{"こよみ", "カレンダー、暦 ", "calendar", "koyomi, karendā"},
{"ふん", "分 ", "minute", "fun"},
{"びょう", "秒 ", "second", "byō"},
{"ひ", "にち、日 ", "day", "hi, nichi"},
{"つき", "げつ、月 ", "month", "tsuki, gatsu"},
{"とし", "ねん、年 ", "year", "toshi, nen"},
{"きのう", "さくじつ、昨日 ", "yesterday", "kinō, sakujitsu"},
{"きょう", "今日 ", "today", "kyō"},
{"あした", "あす、みょうにち、明日 ", "tomorrow", "ashita, asu, myōnichi"},
{"あさ", "朝 ", "morning", "asa"},
{"ひる", "昼 ", "afternoon", "hiru"},
{"ゆうがた", "夕方 ", "evening", "yūgata"},
{"ばん", "晩 ", "evening", "ban"},
{"よる", "夜 ", "evening, night", "yoru"},
{"ようび", "曜日 ", "~day", "yōbi"},
{"げつようび", "月曜日 ", "Monday", "getsu-yōbi"},
{"かようび", "火曜日 ", "Tuesday", "ka-yōbi"},
{"すいようび", "水曜日 ", "Wednesday", "sui-yōbi"},
{"もくようび", "木曜日 ", "Thursday", "moku-yōbi"},
{"きんようび", "金曜日 ", "Friday", "kin-yōbi"},
{"どようび", "土曜日 ", "Saturday", "do-yōbi"},
{"にちようび", "日曜日 ", "Sunday", "nichi-yōbi"},
{"しゅう", "週 ", "week", "shū"},
{"いっしゅうかん", "一週間 ", "one week", "isshūkan"},
{"たいよう", "太陽 ", "sun", "taiyō"},
{"つき", "月 ", "moon", "tsuki"},
{"ほし", "星 ", "star", "hoshi"},
{"てんき", "天気 ", "weather", "tenki"},
{"はれ", "晴れ ", "clear weather", "hare"},
{"あめ", "雨 ", "rain", "ame"},
{"くもり", "曇り ", "cloudy", "kumori"},
{"ゆき", "雪 ", "snow", "yuki"},
{"かぜ", "風 ", "wind", "kaze"},
{"かみなり", "雷 ", "thunder, lightning", "kaminari"},
{"たいふう", "台風 ", "typhoon", "taifū"},
{"あらし", "嵐 ", "storm", "arashi"},
{"そら", "空 ", "sky", "sora"},
{"きた", "北 ", "north", "kita"},
{"ひがし", "東 ", "east", "higashi"},
{"みなみ", "南 ", "south", "minami"},
{"にし", "西 ", "west", "nishi"},
{"ここ", "", "here", "koko"},
{"そこ", "", "there", "soko"},
{"あそこ", "", "over there", "asoko"},
{"みぎ", "右 ", "right", "migi"},
{"ひだり", "左 ", "left", "hidari"},
{"うえ", "上 ", "above, up", "ue"},
{"した", "下 ", "below, down", "shita"},
{"まえ", "前 ", "front", "mae"},
{"うしろ", "後 ", "behind", "ushiro"},
{"むこう", "向こう ", "the other side, opposite side", "mukō"},
{"ななめ", "斜め ", "diagonal", "naname"},
{"てまえ", "手前 ", "nearer, more in front", "temae"},
{"おく", "奥 ", "far", "oku, tooi"},
{"ちかい", "近い ", "near,close", "Chikai"},
{"みず", "水 ", "water", "mizu"},
{"ゆ", "湯 ", "hot water", "yu"},
{"こおり", "氷 ", "ice", "kōri"},
{"ゆげ", "湯気 ", "steam", "yuge"},
{"ひ", "火 ", "fire", "hi"},
{"ガス", "", "gas", "gasu"},
{"くうき", "空気 ", "air, atmosphere", "kūki"},
{"つち", "土 ", "earth, ground", "tsuchi"},
{"きんぞく", "金属 ", "metal, metallic", "kinzoku"},
{"どろ", "泥 ", "mud, mire, clay, plaster", "doro"},
{"けむり", "煙 ", "smoke, tobacco, opium", "kemuri"},
{"てつ", "鉄 ", "iron [Fe]", "tetsu"},
{"どう", "銅 ", "copper [Cu]", "dō"},
{"きん", "金 ", "gold [Au]; money", "kin"},
{"ぎん", "銀 ", "silver [Ag]; wealth", "gin"},
{"なまり", "鉛 ", "lead [Pb]", "namari"},
{"しお", "塩 ", "salt [NaCl]", "shio"},
{"メートル", "", "meter", "mētoru"},
{"リットル", "", "liter", "rittoru"},
{"グラム", "", "gram", "guramu"},
{"キロ", "", "kilo-", "kiro"},
{"ミリ", "", "milli-", "miri"},
{"センチメートル", "センチ", "centimeter ", "senchi"},
{"インチ", "", "inch", "inchi"},
{"しゃかい", "社会 ", "society", "shakai"},
{"けいざい", "経済 ", "economy, economics", "keizai"},
{"かいしゃ", "会社 ", "company", "kaisha"},
{"かいぎ", "会議 ", "meeting", "kaigi"},
{"がっこう", "学校 ", "school", "gakkō"},
{"やくしょ", "役所 ", "local government office", "yakusho"},
{"みせ", "店 ", "store", "mise"},
{"ホテル", "", "hotel", "hoteru"},
{"こうじょう", "工場 ", "factory", "kōjō"},
{"かね", "金 ", "money", "kane, most commonly o-kane"},
{"さつ", "札 ", "bill [of money, e.g., a thousand-yen bill]", "satsu"},
{"こぜに", "小銭 ", "small change", "kozeni"},
{"つりせん", "釣り銭、おつり、お釣り ", "change", "tsurisen"},
{"じどうはんばいき", "自動販売機 ", "vending machine, slot machine", "jidōhanbaiki"},
{"きっぷ", "切符 ", "ticket", "public transport, fine"},
{"きって", "切手 ", "stamp", "kitte"},
{"つくえ", "机 ", "desk", "tsukue"},
{"いす", "椅子 ", "chair, position", "isu"},
{"たたみ", "畳 ", "a tatami mat", "tatami"},
{"と", "戸 ", "door, family", "to"},
{"とびら", "扉 ", "door panel", "tobira"},
{"ドア", "", "door", "doa"},
{"まど", "窓 ", "window", "mado"},
{"ふとん", "布団 ", "futon", "futon"},
{"げんかん", "玄関 ", "entrance", "genkan"},
{"いえ", "家 ", "house, home", "ie"},
{"エレベーター", "", "elevator", "erebētā"},
{"エスカレーター", "", "escalator", "esukarētā"},
{"でんき", "電気 ", "electricity", "denki"},
{"くぎ", "釘 ", "nail, spike", "kugi"},
{"ひも", "紐 ", "string, cord", "himo"},
{"なわ", "縄 ", "rope, string", "nawa"},
{"ふくろ", "袋 ", "pocket, bag", "fukuro"},
{"かばん", "鞄 ", "leather bag", "kaban"},
{"かさ", "傘 ", "umbrella, parasol", "kasa"},
{"かぎ", "鍵 ", "door bolt, key", "kagi"},
{"ちょうこく", "彫刻 ", "sculpture, engraving", "chōkoku"},
{"ぶんぼうぐ", "文房具 ", "stationery", "bunbōgu"},
{"インク", "", "ink", "inku"},
{"ペン", "", "pen", "pen"},
{"ボールペン", "", "ball-point pen", "bōrupen"},
{"まんねんひつ", "万年筆 ", "fountain pen", "mannenhitsu"},
{"えんぴつ", "鉛筆 ", "pencil", "enpitsu"},
{"ふで", "筆 ", "brush for writing or painting", "fude"},
{"チョーク", "", "chalk", "chōku"},
{"けしゴム", "消しゴム ", "eraser", "keshigomu"},
{"えんぴつけずり", "鉛筆削り ", "pencil sharpener", "enpitsu-kezuri"},
{"じょうぎ", "定規 ", "ruler", "jōgi"},
{"ノート", "", "notebook", "nōto"},
{"にっき", "日記 ", "diary", "nikki"},
{"カバー", "", "book cover", "kabā"},
{"ふうとう", "封筒 ", "envelope", "fūtō"},
{"はさみ", "鋏 ", "scissors", "hasami"},
{"ホッチキス", "", "stapler", "hotchikisu"},
{"ふく", "服 ", "clothes", "fuku"},
{"ようふく", "洋服 ", "western clothing", "yōfuku"},
{"きもの", "着物 ", "kimono", "kimono"},
{"わふく", "和服 ", "Japanese clothing", "wafuku"},
{"そで", "袖 ", "sleeve", "sode"},
{"えり", "襟 ", "lapel, collar", "eri"},
{"ボタン", "", "button", "botan"},
{"チャック", "ファスナー、ジッパー ", "zipper, zipper fastener", "chakku, fasunā, jippā"},
{"ベルト", "", "belt", "beruto"},
{"くつ", "靴 ", "shoe", "kutsu"},
{"くつした", "靴下 ", "sock", "kutsushita"},
{"めがね", "眼鏡 ", "glasses", "megane"},
{"てつどう", "鉄道 ", "railway", "tetsudō"},
{"えき", "駅 ", "station", "eki"},
{"ひこうき", "飛行機 ", "airplane", "hikōki"},
{"くうこう", "空港 （ひこうじょう、飛行場） ", "airport", "kūkō, hikōjō"},
{"みち", "道 ", "street, way, road", "michi"},
{"どうろ", "道路 ", "road", "dōro"},
{"バスてい", "バス停 ", "bus-stop", "basutei"},
{"とおり", "通り ", "avenue", "tōri"},
{"でんしゃ", "電車 ", "train", "densha"},
{"じどうしゃ", "自動車 ", "car", "jidōsha"},
{"すうじ", "数字 ", "numbers", "sūji"},
{"アルファベット", "", "alphabet", "arufabetto"},
{"がいこくご", "外国語 ", "foreign language", "gaikokugo"},
{"にほんご", "日本語 （こくご、国語） ", "Japanese [language]", "nihongo"},
{"えいご", "英語 ", "English [language]", "eigo"},
{"ちゅうごくご", "中国語 ", "Chinese [language]", "chūgokugo"},
{"どいつご", "ドイツ語 ", "German [language]", "doitsugo"},
{"すぺいんご", "スペイン語 ", "Spanish [language]", "supeingo"},
{"ふらんすご", "フランス語 ", "French [language]", "furansugo"},
{"ちょうせんご", "朝鮮語、かんこくご、韓国語 ", "Korean [language], South Korean [language]", "chōsengo, kankokugo"},
{"ほん", "本 ", "book", "hon"},
{"かみ", "紙 ", "paper", "kami"},
{"てがみ", "手紙 ", "letter", "tegami"},
{"しんぶん", "新聞 ", "newspaper", "shinbun"},
{"じしょ", "辞書 ", "dictionary", "jisho"},
{"パソコン", "", "personal computer", "pasokon"},
{"いろ", "色 ", "color", "iro, shikisai"},
{"あか", "赤 ", "red", "aka"},
{"きいろ", "黄色 ", "yellow", "kiiro"},
{"みどり", "緑 ", "green", "midori"},
{"あお", "青 ", "blue", "ao"},
{"むらさき", "紫 ", "purple", "murasaki, murasakiiro"},
{"しろ", "白 ", "white", "shiro"},
{"くろ", "黒 ", "black", "kuro"},
{"ピンク", "", "pink", "pinku"},
{"ちゃいろ", "茶色 ", "brown", "chairo"},
{"はいいろ", "灰色、ねずみいろ、鼠色 ", "grey", "haiiro, nezumiiro"},
{"オレンジ", "", "orange", "orenji"},
{"え", "絵 ", "picture", "e"},
{"おんがく", "音楽 ", "music", "ongaku"},
{"りか", "理科 ", "science", "rika"},
{"さんすう", "算数 ", "arithmetic", "sansū"},
{"れきし", "歴史 ", "history", "rekishi"},
{"ちり", "地理 ", "geography", "chiri"},
{"たいいく", "体育 ", "physical education", "taiiku"},
{"スポーツ", "", "sport", "supōtsu"},
{"システム", "", "system", "shisutemu"},
{"じょうほう", "情報 ", "information, news", "jōhō"},
{"ひつよう", "必要 ", "necessity", "hitsuyō"},
{"べんきょう", "勉強 ", "study", "benkyō"},
{"いらい", "依頼 ", "request", "irai"},
{"れい", "ゼロ、零 ", "zero", "rei, zero"},
{"いち", "一 ", "one", "ichi"},
{"に", "二 ", "two", "ni"},
{"さん", "三 ", "three", "san"},
{"よん", "し、四 ", "four", "yon, shi"},
{"ご", "五 ", "five", "go"},
{"ろく", "六 ", "six", "roku"},
{"なな", "しち、七 ", "seven", "nana, shichi"},
{"はち", "八 ", "eight", "hachi"},
{"きゅう", "く、九 ", "nine", "kyū, ku"},
{"じゅう", "十 ", "ten", "jū"},
{"ひゃく", "百 ", "hundred", "hyaku"},
{"せん", "千 ", "thousand", "sen"},
{"まん", "万 ", "ten thousand", "man"},
{"おく", "億 ", "one hundred million", "oku"},
{"ひとつ", "一つ ", "one, one thing", "hitotsu"},
{"ふたつ", "二つ ", "two, two things", "futatsu"},
{"みっつ", "三つ ", "three, three things", "mittsu"},
{"よっつ", "四つ ", "four, four things", "yottsu"},
{"いつつ", "五つ ", "five, five things", "itsutsu"},
{"むっつ", "六つ ", "six, six things", "muttsu"},
{"ななつ", "七つ ", "seven, seven things", "nanatsu"},
{"やっつ", "八つ ", "eight, eight things", "yattsu"},
{"ここのつ", "九つ ", "nine, nine things", "kokonotsu"},
{"とお", "十 ", "ten, ten things", "tō"},
{"これ", "", "this, it", "kore"},
{"それ", "", "that", "sore"},
{"あれ", "", "that over there", "are"},
{"どれ", "", "which", "dore"},
{"こちら", "こっち ", "this direction, thing, person, or place", "kochira, kocchi"},
{"そちら", "そっち ", "that direction, thing, person, or place", "sochira, socchi"},
{"あちら", "あっち ", "that direction, thing, person, or place over there", "achira, acchi"},
{"どちら", "どっち ", "which direction, thing, person, or place", "dochira, docchi"},
{"ひみつ", "秘密 ", "secret", "himitsu"},
{"じどう", "自動 ", "automatic", "jidō"},
{"ないよう", "内容 ", "content", "naiyō"},
{"はば", "幅 ", "hem, piece, strip", "haba"},
{"せいしき", "正式 ", "formality", "seishiki"},
{"けっこん", "結婚 ", "marriage", "kekkon"},
{"げんざい", "現在 ", "now", "genzai"},
{"いま", "今 ", "now", "ima"},
{"かこ", "過去 ", "past", "kako"},
{"みらい", "未来 ", "future", "mirai"},
{"いい", "よい、良い ", "good", "ii, yoi"},
{"すごい", "凄い ", "amazing", "sugoi"},
{"すばらしい", "素晴らしい ", "wonderful", "subarashii"},
{"わるい", "悪い ", "bad, inferior", "warui"},
{"たかい", "高い ", "expensive, high", "takai"},
{"ひくい", "低い ", "low", "hikui"},
{"やすい", "安い ", "cheap", "yasui"},
{"おおきい", "大きい ", "big", "ōkii"},
{"ちいさい", "小さい ", "small", "chiisai"},
{"ほそい", "細い ", "thin", "hosoi"},
{"ふとい", "太い ", "thick", "futoi"},
{"ふるい", "古い ", "old", "furui"},
{"あたらしい", "新しい ", "new", "atarashii"},
{"わかい", "若い ", "young", "wakai"},
{"かるい", "軽い ", "light, easy", "karui"},
{"おもい", "重い ", "heavy", "omoi"},
{"やさしい", "易しい ", "easy, simple", "yasashii"},
{"むずかしい", "難しい ", "difficult", "muzukashii"},
{"やわらかい", "柔らかい ", "soft", "yawarakai"},
{"かたい", "硬い、堅い ", "hard", "katai"},
{"あつい", "熱い、暑い ", "hot", "atsui"},
{"つめたい", "冷たい ", "cold", "tsumetai"},
{"さむい", "寒い ", "cold", "samui"},
{"おいしい", "美味しい ", "delicious", "oishii"},
{"うまい", "美味い、旨い ", "delicious, appetizing", "umai"},
{"まずい", "不味い ", "tastes awful", "mazui"},
{"あまい", "甘い ", "sweet", "amai"},
{"からい", "辛い ", "hot [spicy]", "karai"},
{"しょっぱい", "塩っぱい ", "salty", "shoppai"},
{"にがい", "苦い ", "bitter", "nigai"},
{"うれしい", "嬉しい ", "happy", "ureshii"},
{"かなしい", "悲しい ", "sad", "kanashii"},
{"さびしい", "淋しい ", "lonely", "sabishii"},
{"こわい", "怖い、恐い ", "scary", "kowai"},
{"いたい", "痛い ", "painful", "itai"},
{"かゆい", "痒い ", "itchy", "kayui"},
{"くさい", "臭い ", "stinky", "kusai"},
{"つらい", "辛い ", "painful, heart-breaking", "tsurai"},
{"する", "", "to do", "suru"},
{"やる", "", "to do", "yaru"},
{"いる", "", "to exist [for animate objects]", "iru"},
{"ある", "", "to exist [for inanimate objects]", "aru"},
{"なる", "", "to become", "naru"},
{"おこる", "起こる、興る ", "to occur", "okoru"},
{"現れる", "あらわれる", "to appear ", "arawareru"},
{"いきる", "生きる ", "to live", "ikiru"},
{"うむ", "生む、産む ", "to give birth", "umu"},
{"しぬ", "死ぬ ", "to die", "shinu"},
{"壊れる", "こわれる", "to breakin ", "kowareru"},
{"いく", "行く ", "to go", "iku"},
{"くる", "来る ", "to come", "kuru"},
{"かえる", "帰る、返る ", "to return", "kaeru"},
{"あるく", "歩く ", "to walk", "aruku"},
{"とぶ", "飛ぶ ", "to jump, to fly", "tobu"},
{"うごく", "動く ", "to movein", "ugoku"},
{"おどる", "踊る ", "to dance", "odoru"},
{"ねる", "寝る ", "to sleep", "neru"},
{"うたう", "歌う ", "to sing", "utau"},
{"かむ", "噛む ", "to bite", "kamu"},
{"たべる", "食べる ", "to eat", "taberu"},
{"のむ", "飲む ", "to drink", "nomu"},
{"さわる", "触る ", "to touch", "sawaru"},
{"なげる", "投げる ", "to throw", "nageru"},
{"もつ", "持つ ", "to hold", "motsu"},
{"うつ", "打つ ", "to hit, to strike", "utsu"},
{"なぐる", "殴る ", "to hit, to strike", "naguru"},
{"さす", "指す ", "to point", "sasu"},
{"さす", "刺す ", "to stab", "sasu"},
{"さす", "差す ", "to raise or extend one's hands", "sasu"},
{"ける", "蹴る ", "to kick", "keru"},
{"すわる", "座る ", "to sit", "suwaru"},
{"たつ", "立つ ", "to stand", "tatsu"},
{"はしる", "走る ", "to run", "hashiru"},
{"あく", "空く", "to become unoccupied ", "aku"},
{"こむ", "込む", "to be crowded ", "komu"},
{"いる", "要る", "to need ", "iru"},
{"かわく", "乾く", "to become dry ", "kawaku"},
{"みだす", "乱す", "to disturb, to disarrange ", "midasu"},
{"みだれる", "乱れる", "to be disturbed, to become confused ", "midareru"},
{"つかえる", "仕える", "to serve, to work for ", "tsukaeru"},
{"そなわる", "備わる", "to be furnished with ", "sonawaru"},
{"すぐれる", "優れる", "to excel, to surpass ", "sugureru"},
{"ひえる", "冷える", "to grow cold, to get chilly, to cool down ", "hieru"},
{"さめる", "覚める", "to wake, to become sober, to be disillusioned ", "sameru"},
{"さめる", "冷める", "to cool down ", "sameru"},
{"むく", "向く", "to face, to turn toward ", "muku"},
{"たおれる", "倒れる", "to fall, to collapse ", "taoreru"},
{"かたまる", "固まる", "to harden, to solidify, to become firm ", "katamaru"},
{"うまる", "埋まる", "to be filled, to be surrounded, to overflow ", "umaru"},
{"うもれる", "埋もれる", "to be buried, to be covered ", "umoreru"},
{"ます", "増す", "to increase, to grow ", "masu"},
{"ふえる", "増える", "to increase, to multiply ", "fueru"},
{"へる", "減る", "to decrease ", "heru"},
{"はずれる", "外れる", "to deviate ", "hazureru"},
{"ふとる", "太る", "to grow fat ", "futoru"},
{"はじまる", "始まる", "to begin ", "hajimaru"},
{"おわる", "終わる", "to finish, to close ", "owaru"},
{"きめる", "決める", "to decide ", "kimeru"},
{"みる", "見る ", "to see", "miru"},
{"きく", "聞く、聴く ", "to hear, to listen", "kiku"},
{"さわる", "触る ", "to touch, to feel", "sawaru"},
{"かぐ", "嗅ぐ ", "to smell", "kagu"},
{"いう", "言う ", "to say", "iu"},
{"はなす", "話す ", "to speak", "hanasu"},
{"かたる", "語る ", "to tell", "kataru"},
{"かく", "書く ", "to write", "kaku"},
{"よむ", "読む ", "to read", "yomu"},
{"つかう", "使う ", "to use", "tsukau"},
{"つくる", "作る、造る、創る ", "to make", "tsukuru"},
{"なおす", "直す、治す ", "to fix, repair", "naosu"},
{"すてる", "捨てる ", "to discard, throw away", "suteru"},
{"とる", "取る、撮る、採る ", "to take", "toru"},
{"おく", "置く ", "to put", "oku"},
{"かなしむ", "悲しむ、哀しむ ", "to be sad", "kanashimu"},
{"なく", "泣く ", "to cry", "naku"},
{"わらう", "笑う ", "to laugh", "warau"},
{"おこる", "怒る ", "to be angry", "okoru"},
{"ほめる", "褒める ", "to encourage", "homeru"},
{"しかる", "叱る ", "to scold", "shikaru"},
{"よろこぶ", "喜ぶ ", "to celebrate, to be jubilant, to have joy, to have delight, to have rapture", "yorokobu"},
{"よろこび", "喜び ", "joy, delight, rapture", "yorokobi"},
{"なぐさめる", "慰める ", "to console, to consolate, to provide empathy", "nagusameru"},
{"あきる", "飽きる ", "to be disinterested, to be bored, to be tired of, to be weary", "akiru"},
{"おどろく", "驚く ", "to be astonished, to be surprised, to be scared", "odoroku"},
{"あう", "会う ", "to meet, to interview", "au"},
{"あける", "開ける ", "to opentr, to unwraptr", "akeru"},
{"あそぶ", "遊ぶ ", "to play", "asobu"},
{"あつまる", "集まる ", "to gatherin", "atsumaru"},
{"うる", "売る ", "to sell", "uru"},
{"える", "得る ", "to obtain [some benefit or knowledge]", "eru"},
{"おる", "折る ", "to breaktr, to foldtr", "oru"},
{"かう", "買う ", "to buy", "kau"},
{"きる", "切る ", "to cut", "kiru"},
{"きる", "着る ", "to wear [on the upper body]", "kiru"},
{"はく", "履く ", "to wear [on the lower body]", "haku"},
{"かえる", "変える ", "to changetr", "kaeru"},
{"かえる", "代える ", "to exchange, to substitute, to replace", "kaeru"},
{"しめる", "閉める ", "to closetr", "shimeru"},
{"しめる", "締める ", "to tie, to fasten", "shimeru"},
{"しめる", "占める ", "to comprise, to account for", "shimeru"},
{"しる", "知る ", "to know", "shiru"},
{"つかれる", "疲れる ", "to get tired", "tsukareru"},
{"でかける", "出掛ける ", "to go out, to depart", "dekakeru"},
{"はたらく", "働く ", "to work [e.g., at a job]", "hataraku"},
{"はなす", "放す、離す ", "to let go of", "hanasu"},
{"やすむ", "休む ", "to rest, to take a break, to go to bed", "yasumu"},
{"わかれる", "分かれる ", "to split intoin, to be divided", "wakareru"},
{"わかれる", "別れる ", "to partin, to separatein, to break upin", "wakareru"},
{"もう", "", "already", "mō"},
{"まだ", "", "still, yet", "mada"},
{"ずっと", "", "always", "zutto"},
{"とても", "", "very", "totemo"},
{"こう", "", "like this", "kō"},
{"そう", "", "like that", "sō"},
{"ああ", "", "Oh!, Ah!", "ā"},
{"どう", "", "how", "dō"},
{"しばしば", "", "often", "shibashiba"},
{"この", "", "this", "kono"},
{"その", "", "that", "sono"},
{"あの", "", "that", "ano"},
{"どの", "", "which", "dono"},
{"はい", "", "yes", "hai"},
{"いいえ", "", "no", "iie"},
{"しかし", "", "but, however", "shikashi"},
{"そして", "", "and then, Then…", "soshite"},
{"それに", "", "besides", "soreni"},
{"なぜなら", "", "that is because, being because", "nazenara"},
{"で", "", "at, by", "de"},
{"と", "", "and, with", "to"},
{"に", "", "indirect object marker", "ni"},
{"の", "", "possession marker, of", "no"},
{"へ", "", "to", "e"},
{"まで", "", "to", "made"},
{"から", "", "from", "kara"},
{"より", "", "than", "yori"},
{"を", "", "direct object marker", "o"},
{"は", "", "topic marker", "wa"},
{"も", "", "as well", "mo"},
{"や", "", "and", "ya"},
{"および", "及び ", "and", "oyobi"},
{"か", "", "whether", "ka"},
{"かも", "", "might be, possible that", "kamo"},
{"そして", "", "and then", "soshite"},
{"それとも", "", "or", "soretomo"},
{"だの", "", "things like <list of things>, including, such things as", "dano"},
{"つつ", "", "ongoing occurrence", "tsutsu"},
{"と", "", "when, if, that", "to"},
{"ながら", "", "while, though, both", "nagara"},
{"ならびに", "", "as well as", "narabini"},
{"なり", "", "whether or not", "nari"},
{"に", "", "to <somewhere>, by <someone>", "ni"},
{"の", "", "possession", "no"},
{"ので", "", "so", "node"},
{"また", "又 ", "also, again", "mata"},
{"または", "又は ", "or alternatively", "matawa"},
{"も", "", "also, too", "mo"},
{"や", "", "and", "ya"},
{"かしら", "", "I wonder", "kashira"},
{"こそ", "", "emphasis", "koso"},
{"さえ", "", "even", "sae"},
{"しか", "", "only", "shika"},
{"すら", "", "even", "sura"},
{"くらい", "ぐらい ", "approximately, about", "kurai"},
{"だけ", "", "only, as much as", "dake"},
{"だって", "", "however", "datte"},
{"ったら", "", "casual topic marker", "ttara"},
{"って", "", "said that", "tte"},
{"でも", "", "also, or", "demo"},
{"など", "", "for example", "nado"},
{"なら", "", "if [for verbs]; subject marker [for nouns]", "nara"},
{"なんか", "", "casual undervalue, dislike, lack", "nanka"},
{"は", "", "topic marker", "wa"},
{"ばかり", "ばっかり ", "just, full of, only", "bakari"},
{"まで", "", "until", "made"},
{"も", "", "too, also", "mo"}};



#endif /* japanese_h */
