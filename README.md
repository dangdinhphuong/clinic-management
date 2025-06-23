<h1 class="code-line" data-line-start=0 data-line-end=1 ><a id="_MedicalClinicManager_0"></a>🏥 MedicalClinicManager</h1>
<h2 class="code-line" data-line-start=2 data-line-end=3 ><a id="_M_t_d_n_2"></a>📌 Mô tả dự án</h2>
<p class="has-line-data" data-line-start="3" data-line-end="4"><strong>MedicalClinicManager</strong> là một chương trình quản lý phòng khám đơn giản viết bằng <strong>C++</strong>. Chương trình hỗ trợ:</p>
<ul>
<li class="has-line-data" data-line-start="4" data-line-end="5">Quản lý bệnh nhân và phiếu khám bệnh.</li>
<li class="has-line-data" data-line-start="5" data-line-end="6">Thao tác tìm kiếm, thống kê.</li>
<li class="has-line-data" data-line-start="6" data-line-end="8">Lưu trữ và xử lý dữ liệu.</li>
</ul>
<hr>
<h2 class="code-line" data-line-start=10 data-line-end=11 ><a id="_Cu_trc_th_mc_10"></a>📁 Cấu trúc thư mục</h2>
<p class="has-line-data" data-line-start="12" data-line-end="29">/project<br>
│<br>
├── models/<br>
│ ├── Doctor.h ← Định nghĩa struct Doctor<br>
│ └── Patient.h ← Định nghĩa struct Patient<br>
│<br>
├── structures/<br>
│ ├── Node.h ← Định nghĩa template Node&lt;T&gt;<br>
│ └── LinkedList.h ← Khai báo &amp; triển khai template LinkedList&lt;T&gt;<br>
│<br>
├── core/<br>
│ └── Menu.h ← Khai báo &amp; xử lý menu chính<br>
│<br>
├── main.cpp ← Hàm main(), gọi menu()<br>
├── doctors.txt ← Dữ liệu bác sĩ lưu dạng văn bản<br>
├── patients.txt ← Dữ liệu bệnh nhân lưu dạng văn bản<br>
└── <a href="http://README.md">README.md</a></p>
<hr>
<h2 class="code-line" data-line-start=32 data-line-end=33 ><a id="_Cng_ngh_s_dng_32"></a>🧠 Công nghệ sử dụng</h2>
<ul>
<li class="has-line-data" data-line-start="34" data-line-end="35">🧾 Ngôn ngữ: <strong>C++17</strong></li>
<li class="has-line-data" data-line-start="35" data-line-end="36">💾 Lưu trữ: File <code>.txt</code></li>
<li class="has-line-data" data-line-start="36" data-line-end="38">🧩 Cấu trúc dữ liệu: Template <strong>Linked List</strong></li>
</ul>
<hr>
<h2 class="code-line" data-line-start=40 data-line-end=41 ><a id="_Hng_dn_s_dng_40"></a>📜 Hướng dẫn sử dụng</h2>
<ol>
<li class="has-line-data" data-line-start="42" data-line-end="46">
<p class="has-line-data" data-line-start="42" data-line-end="43"><strong>Biên dịch chương trình</strong>:</p>
<pre><code class="has-line-data" data-line-start="44" data-line-end="46" class="language-bash">   g++ main.cpp core/Menu.cpp -o app -std=c++<span class="hljs-number">17</span>

</code></pre>
</li>
<li class="has-line-data" data-line-start="46" data-line-end="49">
<p class="has-line-data" data-line-start="46" data-line-end="47"><strong>Chạy chương trình</strong>:</p>
<pre><code class="has-line-data" data-line-start="48" data-line-end="49" class="language-bash">./app</code></pre>
</li>
</ol>